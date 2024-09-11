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
    ros::Publisher pcl_pub = nh.advertise<sensor_msgs::PointCloud2>("point_cloud9", 1);

    // Read file pcd
    pcl::PointCloud<pcl::PointXYZ> cloud;
    ROS_INFO("Read point");
    pcl::io::loadPCDFile<pcl::PointXYZ>("/home/dandi/catkin_ws/src/pcl_viewer/data/lioness.pcd", cloud);


    // Convert ke sensor_msgs::PointCloud2
    sensor_msgs::PointCloud2 cloud_msg;
    pcl::toROSMsg(cloud, cloud_msg);
    cloud_msg.header.frame_id = "map"; 

    // Save the rotated point cloud to a new PCD file
    if (pcl::io::savePCDFile("/home/dandi/catkin_ws/src/pcl_viewer/data/rotated_lioness.pcd", cloud) == -1)
    {
        ROS_ERROR("Failed to save PCD file");
        return -1;
    }
    ROS_INFO("Saved rotated point cloud to file");

    ros::Rate rate(1);  // 1 Hz
    while (ros::ok())
    {
        ROS_INFO("Publish cloud msg");
        pcl_pub.publish(cloud_msg);
        ros::spinOnce();
        rate.sleep();
    }
    return 0;
}

