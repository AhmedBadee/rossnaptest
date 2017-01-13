#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <sensor_msgs/Joy.h>

class Servo{

public:
	Servo();

private:
	void callback(const sensor_msgs::Joy::ConstPtr& joy);

	ros::NodeHandle nh;

	int linear, angular;
	double lin_scale, ang_scale;
	ros::Publisher pub;
	ros::Subscriber sub;
};

Servo::Servo():
	linear(1), angular(2) {
				nh.param("axis_linear", linear, linear);
				nh.param("axis_angular", angular, angular);
				nh.param("scale_angular", ang_scale, ang_scale);
				nh.param("scale_linear", lin_scale, lin_scale);

	pub = nh.advertise<geometry_msgs::Twist>("servo", 1);
	sub = nh.subscribe<sensor_msgs::Joy>("joy", 10, &Servo::callback, this);
}

void Servo::callback(const sensor_msgs::Joy::ConstPtr& joy) {
	geometry_msgs::Twist twist;
	twist.angular.z = ang_scale*joy->axes[angular];
	twist.linear.x = lin_scale*joy->axes[linear];
	pub.publish(twist);
}

int main(int argc, char**argv) {
	ros::init(argc, argv, "servo");
	Servo servo;
	ros::spin();
}
