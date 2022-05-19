/*功能：订阅/person_info话题，自定义消息类型learning_topic::Person*/

#include <ros/ros.h>
#include <learning_topic/Person.h>

//接收到订阅消息后，会进入消息回调函数
void personInfoCallback(const learning_topic::Person::ConstPtr& msg)
{
	//将接收到的消息打印出来
	ROS_INFO("Subscribe Person Info:  name:%s  id:%d  banji:%d",msg->name.c_str(), msg->id, msg->banji);
}
int main(int argc, char **argv)
{
	setlocale(LC_ALL,"");//输出中文
	//初始化ROS节点
	ros::init(argc,argv,"person_subscriber");
	//创建节点句柄
	ros::NodeHandle n;
	//创建一个Subscriber，订阅名为/person_info的topic,注册回调函数personInfoCallback
	ros::Subscriber person_info_sub = n.subscribe("/person_info",10,personInfoCallback);
	
	//循环等待回调函数
	ros::spin();//启动了循环，有这句话才能调用回调函数

	return 0;
}
