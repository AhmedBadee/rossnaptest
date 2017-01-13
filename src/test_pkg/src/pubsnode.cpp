// must include to deal with ros libraries
#include <ros/ros.h>
/*
	here you include the msg type you want to deal with
	std_msgs/String
	std_msgs/Int32
	std_msgs/Empty
	std_msgs/Bool
	std_msgs/Float32
*/
#include <std_msgs/Bool.h>


int main(int argc, char** argv)
{
	// initializing the node and passing any parameters given when running
	// NodeName should be unique for each node to be run
	ros::init(argc, argv, "publisher");
	
	// creating a node handle that provides the publishing and subscribing operations
	// "n" is a name you can change
	ros::NodeHandle n;
	// creating the publisher object .. 
	// "myPublisher" is a name you can change
	ros::Publisher myPublisher;
	// assigning the msg type  , topic name and buffer size for publisher object
	// replace "std_msgs::Bool" with your msg type
	// replace "TopicName" with the name you choose
	// replace the buffer size "10" with the size you want
	myPublisher = n.advertise<std_msgs::Bool>("pubs", 10);
	// setting loop rate to 1 Hz
	// this means 1 msg per second
	ros::Rate loop_rate(1);
	// creating a temporary msg to store the data to be published
	std_msgs::Bool msg;
	
	
	while(ros::ok()){
		// dummy code to alternate the data of msg each loop 0 <> 1
		msg.data ^= 1;
		// this line when used will print the msg in the terminal shell
		// in which the publisher node is running
		ROS_INFO("%d",msg.data);
		// publishing the msg
		myPublisher.publish(msg);
		// spinOnce() handles all serial communications when executed
		// sending from publishers to topics and from topics to subscriber callbacks
		ros::spinOnce();
		// waiting some while for the next cycle
		// here we deal with 1 Hz , so it will wait a second
		loop_rate.sleep();
	}
}
