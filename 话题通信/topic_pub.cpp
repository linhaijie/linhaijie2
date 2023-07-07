#include <ros/ros.h>
#include "std_msgs/String.h"
#include <sstream>
#include <iostream>

int main(int argc, char *argv[])
{
//1.发布的话题名称为“iutput_topic”，消息类型为std_msgs::String。
//2.节点名称应为“string_converter”
//3.使用C++编写节点。

    //中文不乱码
    setlocale(LC_ALL,"");
    //初始化节点
    ros::init(argc,argv,"publisher");
    //创建节点句柄
    ros::NodeHandle nh;
    //创建发布者对象,发布的话题名称为“iutput_topic”，消息类型为std_msgs::String。
    ros::Publisher pub = nh.advertise<std_msgs::String>("input_topic",10);
    //调节频率
    ros::Rate rate(10);
    //先创建被发布的消息
    std_msgs::String msg;
    //延迟发送
    ros::Duration(3).sleep();
    //进入循环
    while(ros::ok()){
        msg.data = "hello world";
        pub.publish(msg);
        //检验代码是否有问题
        ROS_INFO("发布的数据是%s",msg.data.c_str());
        //停0.1s
        rate.sleep();
        ros::spinOnce();
    }

    return 0;
}