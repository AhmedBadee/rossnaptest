#!/usr/bin/env python

import rospy
from std_msgs.msg import Bool
from std_msgs.msg import String
from geometry_msgs.msg import Twist
from sensor_msgs.msg import Joy

def callback(data):
	#twist = Twist()
	#twist.linear.x = data.axes[1]
	#twist.angular.z = data.axes[0]
	joyInput = data.axes[1]
	if (joyInput == 1.0):
		state = True
		pub.publish(state)
	elif (joyInput == -1.0):
		state = False
		pub.publish(state)

def listener():
	global pub
	pub = rospy.Publisher('chatter', Bool, queue_size = 10)
	rospy.Subscriber("joy", Joy, callback)
	rospy.init_node('blinkyJoy', anonymous = True)
	rospy.spin()

if __name__ == '__main__':
	listener()
