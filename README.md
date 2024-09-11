# <a href="https://github.com/dansecret/ROS_PointCloud/tree/master">Knowlegde Test, HAMDANDIH</a>

## Part B Programming 
### No.1 The C++ program is the Fibonacci series of n, and from the Fibonacci series of n, which numbers indicate prime numbers
> Open the terminal and go to the folder named Fibonacci

    cd catkin_ws/fibonaci/

> compile file code c++ && run program

    g++ -o fibonaciPrima fibonaciPrima.cpp
    ./fibonaciPrima
> After successfully entering the value n as the Fibonacci value limit, the output will be as shown in the image.
![Screenshot from 2024-09-12 05-09-07](https://github.com/user-attachments/assets/86c963ae-c5a9-48de-9c3d-0e101ae71734)


### No 2 - 4 
> ROS Neotic based program to open point cloud files with .pcd extension, display data on RVIZ and rotate the point cloud data on the Y axis, here I rotate it 90 degrees and save the rotated file .pcd.
> first install ROS <a href="https://wiki.ros.org/noetic/Installation/Ubuntu">Neotic</a>
> After ROS is installed open the terminal then go into the catkin_ws folder

    cd catkin_ws/

> after that run roslaunch

    roslaunch pcl_viewer viewer.launch

> If it is running and RVIZ is open, click add and add the topic that has been created by displaying the contents of the pcd file that is already in the data.
> for more details, here is the <a href="https://drive.google.com/file/d/1eEcYZhWqVPnAl8kJLn5Zys8ldyIoSYla/view?usp=sharing">Video</a>


#### Author
Hamdandih
