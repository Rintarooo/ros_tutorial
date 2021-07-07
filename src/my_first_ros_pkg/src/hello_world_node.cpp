#include <ros/ros.h>                        // ROSヘッダファイル
#include <std_msgs/String.h>
#include <sstream>

int main(int argc, char **argv) {
   ros::init(argc, argv, "hello_world_node");
	ros::NodeHandle nh;
	ros::Publisher chatter_pub = nh.advertise<std_msgs::String>("say_hello_world", 1000);
	ros::Rate rate(10);
	int count = 0;
	while (ros::ok())
	{
		std_msgs::String msg;
		std::stringstream ss;
		ss << "hello world " << count;
		msg.data = ss.str();
		ROS_INFO("%s", msg.data.c_str());
		chatter_pub.publish(msg);
		ros::spinOnce();
		rate.sleep();
		++count;
	}
	return 0;
}

/* http://forestofazumino.web.fc2.com/ros/ros_simple_program.html */
/* 一定周期繰り返し処理 */
// #include <ros/ros.h>                        // ROSヘッダファイル

// int main(int argc, char **argv) {
//   ros::init(argc, argv, "hello");           // ROS初期化（ノード名を"hello"に設定）
//   ros::NodeHandle nh;                       // ノードハンドルの生成
//   ros::Rate rate(1);                        // 周期設定（1Hzに設定）
//   while(ros::ok()) {                        // Ctrl+Cが押されるまで繰り返し
//     ROS_INFO_STREAM("Hello World!");        // 標準出力へ"Hello World"を表示
//     rate.sleep();                           // 指定された周期待ち（ループ内の他処理時間を引いた時間分を待つ）
//   }
// }