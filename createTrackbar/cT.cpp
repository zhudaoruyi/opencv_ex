#include <opencv2\opencv.hpp>
#include <opencv2\highgui\highgui.hpp>
using namespace cv;

#define WINDOW_NAME "【线性混合示例】"

//--------------------【声明全局变量】--------------------
const int g_nMaxAlphaValue = 100; //Alpha值的最大值
int g_nAlphaValueSlider; //滑动条对应的变量
double g_dAlphaValue;
double g_dBetaValue;

//声明存储图像的变量
Mat g_srcImage1;
Mat g_srcImage2;
Mat g_dstImage;

//响应滑动条的回调函数，一个很简单的核心算法
void on_Trackbar(int, void*)
{
	//求出当前alpha值相对于最大值的比例
	g_dAlphaValue = (double)g_nAlphaValueSlider / g_nMaxAlphaValue;
	//beta的值则为1减去alpha值
	g_dBetaValue = (1.0 - g_dAlphaValue);

	//根据alpha和beta值进行线性混合
	addWeighted(g_srcImage1, g_dAlphaValue, g_srcImage2, g_dBetaValue, 0.0, g_dstImage);

	//显示效果图
	imshow(WINDOW_NAME, g_dstImage);
}

//主函数
int main(int argc, char** argv)
{
	//加载图像（两图像的尺寸需相同
	g_srcImage1 = imread("D:/ex/vsprojects/test_opencv_install/createTrackbar/1.png");
	g_srcImage2 = imread("D:/ex/vsprojects/test_opencv_install/createTrackbar/2.png");
	if (!g_srcImage1.data) { printf("读取第一幅图片错误，请确定目录下是否有该图片！ \n"); return -1; }
	if (!g_srcImage2.data) { printf("读取第一幅图片错误，请确定目录下是否有该图片！ \n"); return -1; }

	//设置滑动条初值为70
	g_nAlphaValueSlider = 70;

	//创建窗体
	namedWindow(WINDOW_NAME, 1);

	//在创建的窗体中创建一个滑动条控件
	char TrackbarName[50];
	sprintf(TrackbarName, "透明值 %d", g_nMaxAlphaValue);

	createTrackbar(TrackbarName, WINDOW_NAME, &g_nAlphaValueSlider, g_nMaxAlphaValue, on_Trackbar);

	//结果在回调函数中显示
	on_Trackbar(g_nAlphaValueSlider, 0);
	waitKey(0);
	return 0;
}