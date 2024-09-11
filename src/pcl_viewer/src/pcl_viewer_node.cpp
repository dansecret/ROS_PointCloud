#include <ros/ros.h>
#include <sensor_msgs/PointCloud2.h>
#include <pcl_ros/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/io/pcd_io.h>
#include <pcl/conversions.h>

void pointCloudCallback(const sensor_msgs::PointCloud2ConstPtr& cloud_msg)
{
    ROS_INFO("Received a point cloud message!");
}

int main(int argc, char** argv)
{
    // initial 
    ros::init(argc, argv, "pcl_viewer_node");
    ros::NodeHandle nh;

    // Publisher untuk publish file pcd
    ros::Publisher pcl_pub = nh.advertise<sensor_msgs::PointCloud2>("point_cloud", 1);

    // Read file pcd
    pcl::PointCloud<pcl::PointXYZ> cloud;
    ROS_INFO("Read point");
    pcl::io::loadPCDFile<pcl::PointXYZ>("/home/dandi/catkin_ws/src/pcl_viewer/data/horse.pcd", cloud);


    // Convert ke sensor_msgs::PointCloud2
    sensor_msgs::PointCloud2 cloud_msg;
    pcl::toROSMsg(cloud, cloud_msg);
    cloud_msg.header.frame_id = "map"; 

    ros::Rate rate(30);  // 30 Hz
    while (ros::ok())
    {
        pcl_pub.publish(cloud_msg);
        ros::spinOnce();
        rate.sleep();
    }

    return 0;
}

