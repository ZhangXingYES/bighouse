/*功能：请求spawn服务，服务数据类型为turtlrsim::Spawn*/
#include <ros/ros.h>
#include <turtlesim/Spawn.h>

int main(int argc, char** argv)
{
	//初始化ROS节点
	ros::init(argc,argv,"turtle_spawn");
	//创建节点句柄
	ros::NodeHandle node;
	//发现/spawn服务后，创建一个服务客户端，连接名为/spawn的service
	ros::service::waitForService("/spawn");
	ros::ServiceClient add_turtle = node.serviceClient<turtlesim::Spawn>("/spawn");
	//初始化turtlesim::Spawn（它是自带的消息结构）请求的数据
	turtlesim::Spawn srv;
	srv.request.x = 2.0;
	srv.request.y = 2.0;
	srv.request.name = "turtle2";
	//请求服务调用
	ROS_INFO("Call service to spawn turtle[x:%0.6f, y:%0.6f, name:%s]",
			srv.request.x, srv.request.y, srv.request.name.c_str());
	
	add_turtle.call(srv);//发布消息在客户端里用call，阻塞性函数，会等待服务回复
	
	//显示服务调用结果
	ROS_INFO("Spawnturtle successfully [name:%s]",srv.request.name.c_str());

	return 0;
}
