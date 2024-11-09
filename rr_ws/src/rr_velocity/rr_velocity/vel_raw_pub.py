#!/usr/bin/env python3
# encoding: utf-8

import math
import numpy as np
from math import pi
from time import sleep
import rclpy
from rclpy.node import Node
from rr_msgs.msg import ArmJoint
from rr_msgs.srv import RobotArmArray
from Rosmaster_Lib import Rosmaster
from geometry_msgs.msg import Twist
from std_msgs.msg import Float32, Int32, Bool
from sensor_msgs.msg import Imu, MagneticField, JointState

class RogueRoverDriver(Node):
    def __init__(self,name):
        super().__init__(name)
        self.RA2DE = 180 / pi
        self.car = Rosmaster()
        self.car.set_car_type(2)
        self.pos = [0, 0, 0, 0]

        self.get_logger().info("Initializing RogueRoverDriver node")

        # Declare parameters
        self.imu_link = self.declare_parameter("imu_link", "imu_link").value
        self.Prefix = self.declare_parameter("prefix", "").value
        self.xlinear_limit = self.declare_parameter('xlinear_speed_limit', 1.0).value
        self.ylinear_limit = self.declare_parameter('ylinear_speed_limit', 1.0).value
        self.angular_limit = self.declare_parameter('angular_speed_limit', 5.0).value

        # Create subscriptions
        self.sub_cmd_vel = self.create_subscription(Twist, 'cmd_vel', self.cmd_vel_callback, 10)
        self.sub_RGBLight = self.create_subscription(Int32, "RGBLight", self.RGBLightcallback, 10)
        self.sub_Buzzer = self.create_subscription(Bool, "Buzzer", self.Buzzercallback, 10)
        self.sub_Arm = self.create_subscription(ArmJoint, "TargetAngle", self.Armcallback, 10)

        # Create publishers
        self.ArmPubUpdate = self.create_publisher(ArmJoint, "ArmAngleUpdate", 10)
        self.EdiPublisher = self.create_publisher(Float32, 'edition', 10)
        self.volPublisher = self.create_publisher(Float32, 'voltage', 10)
        self.staPublisher = self.create_publisher(JointState, 'joint_states', 10)
        self.velPublisher = self.create_publisher(Twist, "/vel_raw", 10)
        self.imuPublisher = self.create_publisher(Imu, "/imu/data_raw", 10)
        self.magPublisher = self.create_publisher(MagneticField, "imu/mag", 10)

        # Create service
        self.srv_armAngle = self.create_service(RobotArmArray, "CurrentAngle", self.srv_Armcallback)

        # Initialize joints and set up timer for periodic publishing
        self.joints = [90, 145, 0, 45, 90, 30]
        self.car.set_uart_servo_angle_array(self.joints, 1000)
        self.car.create_receive_threading()

        # Use timer to call pub_data every 0.05 seconds
        self.timer = self.create_timer(0.05, self.pub_data)

    def pub_data(self):
        imu = Imu()
        twist = Twist()
        battery = Float32()
        edition = Float32()
        mag = MagneticField()

        edition.data = float(self.car.get_version())
        battery.data = self.car.get_battery_voltage()

        ax, ay, az = self.car.get_accelerometer_data()
        gx, gy, gz = self.car.get_gyroscope_data()
        mx, my, mz = self.car.get_magnetometer_data()
        vx, vy, angular = self.car.get_motion_data()
        # print(self.car.get_motion_data())

        imu.header.stamp = self.get_clock().now().to_msg()
        imu.header.frame_id = self.imu_link
        imu.linear_acceleration.x = ax
        imu.linear_acceleration.y = ay
        imu.linear_acceleration.z = az
        imu.angular_velocity.x = gx
        imu.angular_velocity.y = gy
        imu.angular_velocity.z = gz

        mag.header.stamp = self.get_clock().now().to_msg()
        mag.header.frame_id = self.imu_link
        mag.magnetic_field.x = mx
        mag.magnetic_field.y = my
        mag.magnetic_field.z = mz

        twist.linear.x = vx
        twist.linear.y = vy
        twist.angular.z = angular

        # Publish data
        self.velPublisher.publish(twist)
        # print(f"Publishing Twist message: linear.x = {twist.linear.x}, linear.y = {twist.linear.y}, angular.z = {twist.angular.z}")

        self.imuPublisher.publish(imu)
        self.magPublisher.publish(mag)
        self.volPublisher.publish(battery)
        self.EdiPublisher.publish(edition)
        self.joints_states_update()

    def cmd_vel_callback(self, msg):
        if not isinstance(msg, Twist):
            return
        vx = msg.linear.x
        vy = msg.linear.y
        angular = msg.angular.z
        self.car.set_car_motion(vx, vy, angular)

    def Armcallback(self, msg):
        if not isinstance(msg, ArmJoint):
            return
        arm_joint = ArmJoint()
        
        if msg.joints:
            arm_joint.joints = self.joints
            for _ in range(2):
                self.car.set_uart_servo_angle_array(msg.joints, msg.run_time)
                self.joints = list(msg.joints)
                self.ArmPubUpdate.publish(arm_joint)
                sleep(0.01)
        else:
            arm_joint.id = msg.id
            arm_joint.angle = msg.angle
            for _ in range(2):
                self.car.set_uart_servo_angle(msg.id, msg.angle, msg.run_time)
                self.joints[msg.id - 1] = msg.angle
                self.ArmPubUpdate.publish(arm_joint)
                sleep(0.01)
                
        self.joints_states_update()
        sleep(0.001)

    def srv_Armcallback(self, request, response):
        response.angles = self.car.get_uart_servo_angle_array()
        return response

    def RGBLightcallback(self, msg):
        if not isinstance(msg, Int32):
            return
        for _ in range(3):
            self.car.set_colorful_effect(msg.data, 6, parm=1)
            sleep(0.01)

    def Buzzercallback(self, msg):
        if not isinstance(msg, Bool):
            return
        for _ in range(3):
            self.car.set_beep(1 if msg.data else 0)
            sleep(0.01)

    def joints_states_update(self):
        state = JointState()
        state.header.stamp = self.get_clock().now().to_msg()
        state.header.frame_id = "joint_states"

        state.name = [f"{self.Prefix}/{name}" for name in ["arm_joint1", "arm_joint2", "arm_joint3", "arm_joint4", "arm_joint5", "grip_joint"]]

        joints = self.joints[:]
        joints[5] = np.interp(joints[5], [30, 180], [0, 90])
        mid = np.array([90, 90, 90, 90, 90, 90])
        position_src = (np.array(joints) - mid) * (pi / 180)

        state.position = position_src.tolist()
        self.staPublisher.publish(state)

    def cancel(self):
        self.car.set_car_motion(0, 0, 0)
        self.get_logger().info("Shutting down the robot...")

def main(args=None):
    rclpy.init(args=args)
    driver = RogueRoverDriver('driver_node')
    try:
        rclpy.spin(driver)
    except KeyboardInterrupt:
        driver.cancel()
    finally:
        driver.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
