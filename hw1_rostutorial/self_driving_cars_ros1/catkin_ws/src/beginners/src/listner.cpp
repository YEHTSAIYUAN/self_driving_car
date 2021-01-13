#include"ros/ros.h"
#include"std_msgs/String.h"

void chatterCallback(const std_msgs::String::ConstPtr& msgs){
    ROS_INFO("I heard: [%s]",msgs->data.c_str());
}
void gps_cb(const geometry_msgs::PointStamped::ConstPtr &gps_msg){
    ROS_WARN_STREAM(gps_msg->header);
}
void lidar_cb(const sensor_msgs::PointCloud2ConstPtr &lidar_msg){  
    ROS_WARN_STREAM(lidar_msg->header);
}
int main(int argc, char **argv){
    ros::init(argc,argv,"listner");
    ros::NodeHandle n;
    // ros::Subscriber sub = n.subscribe("chatter", 1000, chatterCallback);
    ros::Subscriber gps_sub = nh.subscribe("gps", 300, gps_cb);
    ros::Subscriber lidar_sub = nh.subscribe("lidar_points", 300, lidar_cb);
    ros::spin();
    return 0;
}