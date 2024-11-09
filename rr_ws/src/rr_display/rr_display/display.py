#!/usr/bin/env python3

import adafruit_ssd1306
from PIL import Image, ImageDraw, ImageFont
import rclpy
from rclpy.node import Node
from std_msgs.msg import Float32
import socket
import board
import busio
import time

class OLEDBatteryDisplay(Node):
    def __init__(self):
        super().__init__('oled_battery_display')

        # Subscribe to the /voltage topic
        self.subscription = self.create_subscription(
            Float32,
            '/voltage',
            self.battery_callback,
            10
        )

        # Initialize I2C for OLED display
        i2c = busio.I2C(board.SCL, board.SDA, frequency=100000)  # Set frequency to 100kHz
        self.disp = adafruit_ssd1306.SSD1306_I2C(128, 32, i2c, addr=0x3C)

        # Clear display
        self.disp.fill(0)
        self.disp.show()

        # Initialize display buffer
        self.image = Image.new('1', (128, 32))
        self.draw = ImageDraw.Draw(self.image)
        self.font = ImageFont.load_default()
        
        self.percentage = 0.0
        self.ip_address = self.get_ip_address()
        self.ip_timer = self.create_timer(10.0, self.check_ip_update)
        self.update_display()

    def battery_callback(self, msg):
        self.percentage = self.calculate_battery_percentage(msg.data)
        self.update_display()

    def calculate_battery_percentage(self, voltage):
        min_voltage, max_voltage = 9.52, 12.6
        voltage = max(min_voltage, min(voltage, max_voltage))
        return ((voltage - min_voltage) / (max_voltage - min_voltage)) * 100

    def get_ip_address(self):
        s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        try:
            s.connect(('10.254.254.254', 1))
            ip = s.getsockname()[0]
        except Exception:
            ip = 'No IP'
        finally:
            s.close()
        return ip

    def check_ip_update(self):
        new_ip = self.get_ip_address()
        if new_ip != 'No IP':
            self.ip_address = new_ip
            self.get_logger().info(f'IP Address acquired: {self.ip_address}')
            self.update_display()
            self.ip_timer.cancel()

    def update_display(self):
        # Clear the display buffer
        self.disp.fill(0)  # Clear the display first
        self.draw.rectangle((0, 0, 128, 32), outline=0, fill=0)

        # Draw IP address
        self.draw.text((0, 0), f"IP: {self.ip_address}", font=self.font, fill=255)

        padding, battery_width, battery_height = 2, 124, 10
        battery_y_start = 16
        battery_outline = [padding, battery_y_start, battery_width + padding, battery_y_start + battery_height]

        nipple_width, nipple_height = 4, battery_height // 3
        nipple_x_start = battery_outline[2]
        nipple_y_start = battery_y_start + (battery_height - nipple_height) // 2
        battery_nipple = [nipple_x_start, nipple_y_start, nipple_x_start + nipple_width, nipple_y_start + nipple_height]

        inner_width = int((battery_width - 2) * self.percentage / 100)
        inner_rectangle = [padding + 1, battery_y_start + 1, padding + 1 + inner_width, battery_y_start + battery_height - 1]

        self.draw.rectangle(battery_outline, outline=255, fill=0)
        self.draw.rectangle(battery_nipple, outline=255, fill=255)
        self.draw.rectangle(inner_rectangle, outline=255, fill=255)

        # Display image on OLED
        self.disp.image(self.image)
        self.disp.show()
        time.sleep(0.05)  # Small delay to help reduce flickering


def main(args=None):
    rclpy.init(args=args)
    oled_battery_display = OLEDBatteryDisplay()
    rclpy.spin(oled_battery_display)
    oled_battery_display.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
