/*功能：*/执行/turtle_command服务，服务数据类型为std_srvs/Trigger
#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <std_srvs/Trigger.h>

ros::Publisher turtle_vel_pub;
bool pubCommand = false;
// service回调函数，输入参数req，输出参数res
bool commandCallback(std_srvs::Trigger::Request &req,td_srvs::Trigger::Response &res)
{
	pubCommand = !pubCommand;
	//显示请求的数据
	ROS_INFO("Publisher turtle velocity command [%s]", pubCommand == true?"Yes":"No");
	//设置反馈数据
	res.success = true;
	res.message = "Change turtle command state!";
	
	return true;
}
int main(int argc, char **argv)
{
	//ROS节点初始化
	ros::init(argc, argv, "turtle_command_server")
	//创建节点名
	ros::NodeHandle n;
	//创建一个名为/turtle_command的server，注册回调函数commandCallback
	ros::ServiceServer command_service = n.advertiseService("/turtle_command", commandCallback);
	//循环等待回调函数
	ROS_INFO("Ready to revice turtle command.");
	//设置循环的频率
	ros::Rate loop_rate(10);
	
	while(ros::ok())
	{
		//查看一次回调函数队列
		ros::SpinOnce;
		//如果标志为true,则发布速度指令
		if(pubCommand)
		{
			geometry_mesg::Twist vel_msg;
			vel_msg.linear.x = 0.5;
			vel_msg.angular.z = 0.2;
			turtle_vel_publish(vel_msg);
			
		
		}
		loop_rate.sleep();
		
	}
	
	return 0;

}
