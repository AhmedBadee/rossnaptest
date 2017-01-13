#!/usr/bin/env python

import rospy
from std_msgs.msg import UInt16
from sensor_msgs.msg import Joy

def callback(data):
	global angle

	joyInput = data.axes[1]

	if joyInput == 1.0:
		if angle == 180:
			angle = 180
			pub.publish(angle)
		else:
			angle += 15
			pub.publish(angle)

	elif joyInput == -1.0:
		if angle == 0:
			angle = 0
			pub.publish(angle)
		else:
			angle -= 15
			pub.publish(angle)

def listener():
	global pub
	pub = rospy.Publisher('servo', UInt16, queue_size = 10)
	rospy.Subscriber('joy', Joy, callback)
	rospy.init_node('servo_node', anonymous = True)
	rospy.spin()

if __name__ == '__main__':
	angle = 0
	listener()
