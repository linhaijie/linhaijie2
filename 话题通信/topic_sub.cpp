#include "ros/ros.h"
#include "std_msgs/String.h"
//回调函数
void doMsg(const std_msgs::String::ConstPtr &msg)
{
    ROS_INFO("接收到的数据是%s",msg->data.c_str());
}
int main(int argc, char *argv[])
{
     
    //订阅的话题名称为“input_topic”，消息类型为std_msgs::String。
    
    setlocale(LC_ALL,"");
    //初始化 ROS 节点
    ros::init(argc,argv,"listener");
    //创建节点句柄
    ros::NodeHandle nh;
    //创建订阅者对象
    ros::Subscriber sub = nh.subscribe("output_topic",10,doMsg);
    //处理订阅到的数据
    //回调函数
    ros::spin();

    return 0;
}