#include "husky_highlevel_controller/HuskyHighlevelController.hpp"
#include <std_msgs/String.h>
#include <ros/ros.h>
#include <sensor_msgs/LaserScan.h>

namespace husky_highlevel_controller {


HuskyHighlevelController::HuskyHighlevelController(ros::NodeHandle& nodeHandle) :
  nodeHandle_(nodeHandle)
{

	nodeHandle.getParam("/husky_highlevel_controller/husky/topic_name",topic_name);
	nodeHandle.getParam("/husky_highlevel_controller/husky/queue_size",queue_size);
	ROS_INFO("Topic : %d QueueSize",queue_size);
	laser_scan_subscriber = nodeHandle.subscribe(topic_name, queue_size, &HuskyHighlevelController::laserScanCallback,this);
	ros::spin();
}

HuskyHighlevelController::~HuskyHighlevelController()
{
}


void HuskyHighlevelController::laserScanCallback(const sensor_msgs::LaserScan::ConstPtr& msg)
{
	laser_scan_distance=msg->ranges;

	minDistance=30;
	int len=laser_scan_distance.size();
	for(int i=0;i<len;i++)
	{
		if(laser_scan_distance[i]<minDistance)
		{
			minDistance=laser_scan_distance[i];

		}

	}
	ROS_INFO("Distance : %f",minDistance);




}

}
 /* namespace */

