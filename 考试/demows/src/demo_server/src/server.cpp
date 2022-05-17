#include "ros/ros.h"
#include "demo_server/AddTwoInts.h"//自定义服务

bool add(demo_server::AddTwoInts::Request  &req,
         demo_server::AddTwoInts::Response &res)
//注意参数的写法：包名，自定义srv文件名
{
  res.sum = req.a + req.b;
  ROS_INFO("request: x=%ld, y=%ld", (long int)req.a, (long int)req.b);
  ROS_INFO("sending back response: [%ld]", (long int)res.sum);
  return true;
    //此处，两个整数被相加，和已经存储在了响应中。然后记录一些有关请求和响应的信息到日志中。完成后，服务返回true。
}
//这个函数提供了AddTwoInts服务，它接受srv文件中定义的请求（request）和响应（response）类型，并返回一个布尔值。

int main(int argc, char **argv)
{
  ros::init(argc, argv, "add_two_ints_server");
  ros::NodeHandle n;

  ros::ServiceServer service = n.advertiseService("add_two_ints", add);
  //服务被创建，并在ROS中宣告，服务名为add_two_ints
  //发布服务，因为服务不用循环发布，所以不用死循环（没有设置循环频率）。
  //add应该就是上面调用函数的名称，应该是收到客户端的请求后，会调用的函数
    
  ROS_INFO("Ready to add two ints.");
  ros::spin();//有这段应该是就可以调用上面的函数

  return 0;
}
