#include <ros/ros.h>
#include <sensor_msgs/PointCloud2.h>
#include <pcl_ros/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/common/transforms.h>
#include <Eigen/Dense> // For Eigen::Matrix4f
#include <cmath>      // For M_PI

class PointCloudTransformer
{
public:
    PointCloudTransformer()
    : rotation_angle(0.0)
    {
        // Initialize ROS node handle and subscribers
        point_cloud_sub = nh.subscribe("point_cloud9", 1, &PointCloudTransformer::pointCloudCallback, this);
        point_cloud_pub = nh.advertise<sensor_msgs::PointCloud2>("transformed_point_cloud", 1);
    }

    void pointCloudCallback(const sensor_msgs::PointCloud2ConstPtr& input_msg)
    {
        // Create a PCL point cloud from the sensor_msgs::PointCloud2 message
        pcl::PointCloud<pcl::PointXYZ> pcl_cloud;
        pcl::fromROSMsg(*input_msg, pcl_cloud);

        float rotation_angle = M_PI/2;


        // Create a transformation matrix for rotation around the Y axis
        Eigen::Matrix4f transform = Eigen::Matrix4f::Identity();
        transform(0, 0) = cos(rotation_angle);
        transform(0, 2) = sin(rotation_angle);
        transform(2, 0) = -sin(rotation_angle);
        transform(2, 2) = cos(rotation_angle);

        ROS_INFO("Rotation angle (radians): %f", rotation_angle);

        // Apply the transformation
        pcl::PointCloud<pcl::PointXYZ> transformed_cloud;
        pcl::transformPointCloud(pcl_cloud, transformed_cloud, transform);

        // Convert back to sensor_msgs::PointCloud2
        sensor_msgs::PointCloud2 output_msg;
        pcl::toROSMsg(transformed_cloud, output_msg);
        output_msg.header = input_msg->header; // Keep the same header

        // Publish the transformed point cloud
        point_cloud_pub.publish(output_msg);
    }

private:
    ros::NodeHandle nh;
    ros::Subscriber point_cloud_sub;
    ros::Publisher point_cloud_pub;
    float rotation_angle; // Current rotation angle in radians
};

int main(int argc, char** argv)
{
    ros::init(argc, argv, "pointcloud_transformer");
    PointCloudTransformer transformer;
    ros::spin();
    return 0;
}
