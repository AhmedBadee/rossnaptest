#!/usr/bin/env python

import rospy
from std_msgs.msg import String

def talker():
	pub = rospy.Publisher('chatter', String, queue_size = 10)   #Publisher(topic name, class String, limitation of the queued messages)
	rospy.init_node('talker', anonymous=True)
	rate = rospy.Rate(10)                                        #lopping 10 times per second
	while not rospy.is_shutdown():
		blink_str = "blink"
		rospy.loginfo(blink_str)
		pub.publish(blink_str)
		rate.sleep()

if __name__ == '__main__':
	try:
		talker()
	except rospy.ROSInterruptException:
		pass
