#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>
using namespace cv;

int main()
{
	// 图像的载入和显示
	Mat girl = imread("D:/ex/vsprojects/test_opencv_install/tuxiangzairuxianshishuchu/3.png");
	namedWindow("【1】动漫图");
	imshow("【1】动漫图", girl);

	// 初级图像混合，载入图片
	Mat image = imread("D:/ex/vsprojects/test_opencv_install/tuxiangzairuxianshishuchu/1.png");
	Mat logo = imread("D:/ex/vsprojects/test_opencv_install/tuxiangzairuxianshishuchu/2.png");
	// 载入后显示
	namedWindow("【2】原图片");
	imshow("【2】原图片", image);

	namedWindow("【3】logo图");
	imshow("【3】logo图", logo);

	// 定义一个Mat类型，用于存放图像的ROI
	Mat imageROI;
	// 方法一
	imageROI = image(Rect(12, 100, logo.cols, logo.rows));
	// 方法二
	//imageROI = image(Range(100, 100 + logo.rows), Range(80, 80 + logo.cols));

	// 将logo加到原图上
	addWeighted(imageROI, 0.5, logo, 0.3, 0., imageROI);

	// 显示结果
	namedWindow("【4】原画+logo图");
	imshow("【4】原画+logo图", image);

	// 图像的输出
	imwrite("由imwrite生产图片.jpg", image);
	waitKey();
	return 0;
}