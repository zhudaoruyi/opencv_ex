#include <opencv2\opencv.hpp>
using namespace cv;

int main()
{
	// 从摄像头读入视频
	VideoCapture capture(0);
	Mat edges;

	// 循环显示每一帧
	while (1)
	{
		Mat frame; //定义一个Mat变量，用于存储每一帧的图像
		capture >> frame; //读取当前帧

		// 灰度处理
		cvtColor(frame, edges, CV_BGR2GRAY);

		//降噪
		blur(edges, edges, Size(7, 7));

		//进行canny边缘检测并显示
		Canny(edges, edges, 0, 30, 3);
		imshow("读取canny后的视频", edges); //显示

		if(waitKey(300)>=0) break; //延时 30ms
	}
	imshow("result", edges);
	waitKey(0);
	return 0;
}