#pragma once

#include <ros/ros.h>
#include <std_msgs/String.h>
#include <sensor_msgs/LaserScan.h>
#include <vector>
#include <string>
#include<std_msgs/Float32.h>

using std::vector;
using std::string;

namespace husky_highlevel_controller {

/*!
 * Class containing the Husky Highlevel Controller
 */
class HuskyHighlevelController {
public:
	/*!
	 * Constructor.
	 */
	HuskyHighlevelController(ros::NodeHandle& nodeHandle);

	/*!
	 * Destructor.
	 */
	virtual ~HuskyHighlevelController();

private:
	ros::NodeHandle nodeHandle_;
	void laserScanCallback(const sensor_msgs::LaserScan::ConstPtr& msg);
	vector<float> laser_scan_distance;
	float minDistance;
	int queue_size;
	string topic_name;

	ros::Subscriber laser_scan_subscriber;
};

} /* namespace */
