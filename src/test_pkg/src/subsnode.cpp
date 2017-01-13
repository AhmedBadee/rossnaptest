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

// this function is executed every time a message reach the topic and to be subscribed
// handled after ros::spin() function call
void callBack(const std_msgs::Bool msg){
	// this line print the msg content in the terminal shell where the node is running
	ROS_INFO("%d", msg.data);
}

int main(int argc,char **argv){
	// initializing the node and passing any parameters given when running
	// NodeName should be unique for each node to be run
	ros::init(argc,argv,"subscriber");
	
	// creating a node handle that provides the publishing and subscribing operations
	// "n" is a name you can change
	ros::NodeHandle n;
	// creating the publisher object .. 
	// "mySubscriber" is a name you can change
	ros::Subscriber mySubscriber;
	// assigning the topic, buffer size and callback function for the subscriber object
	// replace "TopicName" with topic you want to subscribe from
	// replace "10" with the buffer size you want
	// replace "callBack" with the function name you implement for subscribtion
	mySubscriber = n.subscribe("pubs",10,callBack);
	// this command is executed continueously and handle any message comming in topic
	// it passes the messages to the corresponding callBack functions
	ros::spin();

	return 0;
}
