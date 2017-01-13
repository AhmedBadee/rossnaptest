#include "ros/ros.h"
#include "testmsg/poto.h"

int main(int argc, char **argv) {
	ros::init(argc, argv, "talker");
	ros::NodeHandle nh;

	ros::Publisher pub = nh.advertise<testmsg::poto>("chatter", 1000);
	
	ros::Rate loop_rate(10);

	int count = 0;
	while (ros::ok()) {
		testmsg::poto msg;

		msg.name = "ahmed";
		msg.id = 50;

		pub.publish(msg);
		
		ros::spinOnce();
		loop_rate.sleep();
		++count;
	}

	return 0;
}

