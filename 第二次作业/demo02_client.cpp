include "ros/ros.h"
#include "plumbing_server_client/AddInts.h"

int main(int argc, char *argv[])
{ 
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"add_two_ints_client");
    ros::NodeHandle nh;
    ros::ServiceClient client = nh.serviceClient<plumbing_server_client::AddInts>("AddTwoInts");
    plumbing_server_client::AddInts ai; 
    ai.request.a = 100; 
    ai.request.b = 200;
    bool flag = client.call(ai);
    if (flag){ 
        ROS_INFO("响应成功！"); 
    ROS_INFO("响应结果 = %d",ai.response.sum); 
        }else{ 
            ROS_INFO("响应失败！"); 
            }
    return 0;
}