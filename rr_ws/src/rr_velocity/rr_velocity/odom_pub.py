import rclpy
from rclpy.node import Node
from nav_msgs.msg import Odometry
from geometry_msgs.msg import Twist, Quaternion
from tf_transformations import quaternion_from_euler
from rclpy.time import Time
import math

class OdomPublisher(Node):
    def __init__(self):
        super().__init__('odom_publisher')
        
        # Initialize parameters
        self.linear_scale_x = self.declare_parameter("linear_scale_x", 1.0).value
        self.linear_scale_y = self.declare_parameter("linear_scale_y", 1.0).value
        self.odom_frame = self.declare_parameter("odom_frame", "odom").value
        self.base_footprint_frame = self.declare_parameter("base_footprint_frame", "base_footprint").value
        
        # Initialize variables
        self.linear_velocity_x = 0.0
        self.linear_velocity_y = 0.0
        self.angular_velocity_z = 0.0
        self.last_vel_time = self.get_clock().now()
        self.vel_dt = 0.0
        self.x_pos = 0.0
        self.y_pos = 0.0
        self.heading = 0.0

        # Create subscriber and publisher
        self.velocity_subscriber = self.create_subscription(
            Twist, '/vel_raw', self.vel_callback, 50)
        self.odom_publisher = self.create_publisher(
            Odometry, '/odom_raw', 50)

    def vel_callback(self, twist):
        current_time = self.get_clock().now()
        self.vel_dt = (current_time - self.last_vel_time).nanoseconds / 1e9  # Convert to seconds
        self.last_vel_time = current_time

        # Apply scaling to velocities
        self.linear_velocity_x = twist.linear.x * self.linear_scale_x
        self.linear_velocity_y = twist.linear.y * self.linear_scale_y
        self.angular_velocity_z = twist.angular.z

        # Compute odometry
        delta_heading = self.angular_velocity_z * self.vel_dt
        delta_x = (self.linear_velocity_x * math.cos(self.heading) - self.linear_velocity_y * math.sin(self.heading)) * self.vel_dt
        delta_y = (self.linear_velocity_x * math.sin(self.heading) + self.linear_velocity_y * math.cos(self.heading)) * self.vel_dt

        # Update position
        self.x_pos += delta_x
        self.y_pos += delta_y
        self.heading += delta_heading

        # Create quaternion for heading
        odom_quat = Quaternion()
        q = quaternion_from_euler(0, 0, self.heading)
        odom_quat.x, odom_quat.y, odom_quat.z, odom_quat.w = q

        # Populate and publish odometry message
        odom = Odometry()
        odom.header.stamp = current_time.to_msg()
        odom.header.frame_id = self.odom_frame
        odom.child_frame_id = self.base_footprint_frame

        # Set position and orientation
        odom.pose.pose.position.x = self.x_pos
        odom.pose.pose.position.y = self.y_pos
        odom.pose.pose.position.z = 0.0
        odom.pose.pose.orientation = odom_quat
        odom.pose.covariance[0] = 0.001
        odom.pose.covariance[7] = 0.001
        odom.pose.covariance[35] = 0.001

        # Set linear and angular velocities
        odom.twist.twist.linear.x = self.linear_velocity_x
        odom.twist.twist.linear.y = self.linear_velocity_y
        odom.twist.twist.linear.z = 0.0
        odom.twist.twist.angular.x = 0.0
        odom.twist.twist.angular.y = 0.0
        odom.twist.twist.angular.z = self.angular_velocity_z
        odom.twist.covariance[0] = 0.0001
        odom.twist.covariance[7] = 0.0001
        odom.twist.covariance[35] = 0.0001

        # Publish odometry message
        self.odom_publisher.publish(odom)


def main(args=None):
    rclpy.init(args=args)
    node = OdomPublisher()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()

