/*功能：发布/person_info话题，自定义消息类型learning_topic::Person*/

#include <ros/ros.h>
#include <demo_topic/Person.h>//包含话题消息类型，先前编译.msg文件生成的.h文件

int main(int argc,char **argv)
{
	setlocale(LC_ALL,"");//输出中文
	//ROS节点初始化
	ros::init(argc,argv,"person_publisher");//同时创建一个节点，名字为person_publisher
	//创建节点句柄
	ros::NodeHandle n;
	//创建一个Publisher,发布名为/person_info的topic,消息类型为learning_topic::Person，队列长度为10
	ros::Publisher person_info_pub = n.advertise<demo_topic::Person>("/person_info",10);
	//设置循环的频率
	ros::Rate loop_rate(1);
	
	int count = 0;
	while (ros::ok())
	{
		//初始化learning_topic::Person类型的消息
		demo_topic::Person person_msg;
		person_msg.name  = "张兴";
		person_msg.id    = 2019075074;
		person_msg.banji = 192;
		
		//发布消息
		person_info_pub.publish(person_msg);
		
		ROS_INFO("Publish Person Info: name:%s  id:%d  banji:%d",person_msg.name.c_str(),person_msg.id, person_msg.banji);
		
		//按照循环频率延时
		loop_rate.sleep();
	}

	return 0;
}
