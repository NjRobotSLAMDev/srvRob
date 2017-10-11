#ifndef WEBHANDLER_H
#define WEBHANDLER_H

#include "ros/ros.h"
#include "Socket.h"
#include "geometry_msgs/PoseStamped.h"
#include <string>
#include <cstring>
#include <tf/tf.h>
#include <sstream>

class WebHandler{
private:
	SocketClient sock;
	ros::NodeHandle nHandle;
	ros::Publisher goalPub;
	ros::Subscriber poseSub;
	geometry_msgs::PoseStamped robotPose;

public:
	WebHandler(const char* ip="192.168.1.250",unsigned short int port=9999);

private:
	void onSubPose(const geometry_msgs::PoseStamped::ConstPtr& msg);
	void pubGoal();
	void motion();
	void updateMap();
	void getPose();
};


#endif
