              　  ########ROS使用（古月入门21讲）###########

*******************要用ROS，首先需要创建工作空间，类似新建工程************************
-----------------------------------------------------------------------------------
创建工作空间：							
   ①创建工作空间
    $ mkdir -p ~/catkin_zx/src   (创建工作空间文件夹以及catkin_zx文件夹下的src文件)
    $ cd ~/catkin_zx/src   (进入到文件夹src)
    $ catkin_init_workspace   (初始化工作空间)
   ②编译工作空间
    $ cd ~/catkin_zx/   (进入文件夹catkin_zx)
$ catkin_make   (编译工作空间)
要产生install空间：
$ catkin_make install
   ③设置环境变量
    $ source devel/setup.bash
   ④检查环境变量
    $ echo $ROS_PACKAGE_PATH
创建功能包：
   ①创建功能包：	
    $ cd ~/catkin_zx/src   (进入到文件夹src)
    $ catkin_create_pkg package_name depend1 depend2 depend3...
   ②编译功能包
    $ cd ~/catkin_zx
    $ catkin_make
    $ source ~/catkin_zx/devel/setup.bash   (设置环境变量)
----------------------------------------------------------------------------------
------------文件夹说明----------
工作空间的4个文件：
    src：放功能包原码
    install：安装空间，放最终编译生成的可执行文件
    build：编译过程中的一些二进制文件，基本用不到
    devel：开发空间，开发过程中的可执行文件，包括一些库，类似install是最终结果，发给客户
	使用的文件
功能包的文件：
    include：放头文件，如c++的.h文件
    src：放功能包的代码，或代码文件
    CMakeList.txt
package.xml
-------------------------------
***********************************************************************************





　　　　　　　＊＊＊＊＊＊＊＊＊＊学习话题（topic）订阅者与发布者＊＊＊＊＊＊＊＊
ROS Topic概念:
  ROS Node之间进行通信所利用的最重要的机制就是消息传递，在ROS中，消息有组织的放到Topic里
进行传递。
Publisher:
  生成信息，通过ROS Topic与其它Node进行通信。
  通常用于处理原始的传感器信息，如相机、编码器等。
Subscriber:
  接收信息，通过ROS Topic接收来自其它Node的信息，并通过回调函数处理
  通常用于监测系统状态，如当机器人关节到达限位位置时触发运动中断
Topic通信过程为：
    1,Publisher节点和Subscriber节点分别在Master进行注册
    2,Publisher发布Topic
    3,Subscriber在Master指挥下订阅Topic，从而建立起Pub-Sub之间的通信

在相应工作空间创建相关功能包：
    $ catkin_create_pkg learning_topic roscpp rospy std_msgs geometry_msgs turtlesim

创建发布者（代码C++，在功能包的src文件里创建）
 




创建订阅者（代码python，功能包下从新创建一个文件夹scripts）
 
注意：
1，编译程序之前一定要设置环境变量：
	在工作空间根路径下，执行source devel/setup.bash
	但新开一个终端后就不起作用了，解决方法：
	在home/user下，Ctrl+h显示隐藏文件，打开其中的.bashrc,在最下面添加/home/用户名、工作空间名/devel//setup.bash
2，创建完发布者或订阅者后，C++代码需要在对应功能包下面的CMakeList.txt设置编译规则：
	1，设置需要编译的代码和生成的可执行文件
	2，设置链接库
	3，添加依赖项（自定义消息时才有）
在CMakeList.txt的build部分添加：
add_executable(编译生成的可执行文件名 src/编译的文件)
target_link_libraries(编译生成的可执行文件名 ${catkin_LIBRARIES})

说明：可执行文件在工作空间/devel/lib/功能包名/编译生成的可执行文件名
3，如果用的python(不用编译)，
1，将python文件与C++文件分开放，在功能包下从新创建一个文件夹scripts，
将python文件放在里面
	2，让python文件有可执行权限：文件右击属性，执行打✔
		
＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊



#############################12讲（话题消息的定义与使用）########################
说明：前面2讲的消息都是用的ROS自定义的消息，为了满足自己的开发，需要自定义消息，编写发布者，订阅者，实现消息的传输（年龄，性别等）
***1,自定义话题消息：********************************************************
 
1,定义msg文件：在功能包下新建文件夹msg,将定义好的话题消息放在里面
2,添加依赖(两个固定的依赖)：
	编译依赖：依赖动态产生msg功能的依赖包（message_generation）
			<build_depend>message_generation</build_depend>
	执行依赖：运行时的依赖（message_runtime）
			<exec_depend> message_runtime </exec_depend>
3,添加编译选项：
	①find_package(…… message_generation):因为依赖的包message_generation跟编译构建有关
	②add_message_files(FILES Person.meg):把先定义的Person.msg作为定义的消息接口，编译时会找到消息接口，针对这个消息接口编译
	  generate_messages(DEPENDENCIES std_msgs)：添加在编译.msg文件时需要依赖的ROS已有的包（如，自己写的.msg文件的格式，符号在std_msgs有定义）
	③catkin_lackage(…… message_runtime)：创建message运行的依赖
4,编译
编译.msg文件后会生成一个代码文件；位置，工作空间/devel/include/功能包/(.msg文件名).h














***2使用自定义的话题消息*******************************************************
1,创建发布者代码（C++）：
 
2,创建订阅者代码（C++）
 
3,创建完发布者或订阅者后，C++代码需要在对应功能包下面的CMakeList.txt设置编译规则：
	1,设置需要编译的代码和生成的可执行文件
	2,设置链接库
	3,添加依赖项
在CMakeList.txt的build部分添加：（自定义话题消息还要添加其他项）
add_executable(编译生成的可执行文件名 src/编译的文件)
target_link_libraries(编译生成的可执行文件名 ${catkin_LIBRARIES})
4,编译
	在工作空间根目录下，运行catkin_make
5,运行测试
	步骤：
	①，新开终端运行：roscore
	②，新开终端运行订阅者：rosrun learning_topic person_subscriber
	③，新开终端运行发布者：rosrun learning_topic person_publisher
###################***13讲.Client的编程实现（Server部分）***####################
在原先的工作空间里，创建一个新的功能包用于学习service
在功能包里的src文件夹下，创建客户端代码：
 
Py程序：
 


#########################***14讲.服务端Service的编程实现***#####################
 



