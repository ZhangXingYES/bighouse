#include "ros/ros.h"
#include "demo_server/AddTwoInts.h"
#include <cstdlib>//用于srv.request.a = atoll(argv[1]);的atoll函数

int main(int argc, char **argv)
{
  ros::init(argc, argv, "add_two_ints_client");//初始化，节点：add_two_ints_client
  if (argc != 3)
  {
    ROS_INFO("usage: add_two_ints_client X Y");//提示信息
    return 1;
  }

  ros::NodeHandle n;
  ros::ServiceClient client = n.serviceClient<demo_server::AddTwoInts>("add_two_ints");
  //为add_two_ints服务创建一个客户端。ros::ServiceClient对象的作用是在稍后调用服务。
    
  demo_server::AddTwoInts srv;//实例化一个自定义的服务类
  srv.request.a = atoll(argv[1]);
  srv.request.b = atoll(argv[2]);
  if (client.call(srv))
  //此处实际上调用了服务。由于服务调用被阻塞，它将在调用完成后返回。
  //如果服务调用成功，call()将返回true，并且srv.response中的值将是有效的。
  //如果调用不成功，则call()将返回false且srv.response的值将不可用。
  {
    ROS_INFO("Sum: %ld", (long int)srv.response.sum);
  }
  else
  {
    ROS_ERROR("Failed to call service add_two_ints");
    return 1;
  }

  return 0;
}
