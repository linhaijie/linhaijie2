#include "ros/ros.h"
#include "std_msgs/String.h"
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <cctype>


//设置节点变量
static ros::Subscriber sub0;
static ros::Publisher pub0;
//处理数据
void xxxx(const std_msgs::String::ConstPtr& msg){

    std::string msg1 = msg->data;

    std_msgs::String msg2;
    //调用函数
    std::transform(msg1.begin(),msg1.end(),msg1.begin(),::toupper);

    msg2.data = msg1;
    //发布数据
    pub0.publish(msg2);
}

int main(int argc, char *argv[])
{
    //中文不乱码
    setlocale(LC_ALL,"");
    //初始化节点
    ros::init(argc,argv,"string_converter");
    //创建节点句柄
    ros::NodeHandle string_convert;

    sub0 = string_convert.subscribe("input_topic",10,xxxx);

    pub0 = string_convert.advertise<std_msgs::String>("output_topic",10);
    //
    ros::spin();

    return 0;
}