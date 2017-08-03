#include <opencv2\opencv.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>
using namespace cv;

int main()
{
	// 载入原始图
	Mat src = imread("D:/ex/vsprojects/test_opencv_install/canny_bianyuanjiance/mt.jpg");
	Mat src1 = src.clone();

	// 显示原始图
	imshow("【原始图】canny边缘检测", src);

	//--------------------------------------------------
	// 方法一：最简单的canny用法，拿到原图后直接用。
	// 注意：次方法在opencv2中可用，在opencv3中已经失效
	//--------------------------------------------------
	//Canny(srcImage,srcImage,150,100,3);
	//imshow("【效果图】canny边缘检测",srcImage);

	//--------------------------------------------------
	//方法二、高阶的canny用法，转成灰度图，降噪，用canny，最后将得到的边缘作为掩码，拷贝原图到效果图上，得到彩色的边缘图
	//--------------------------------------------------
	Mat dst, edge, gray;

	//创建与src同类型和大小的矩阵（dst）
	dst.create(src1.size(), src1.type());

	//将原图像转为灰度图像
	cvtColor(src1, gray, COLOR_BGR2GRAY);

	//先用3X3内核来降噪
	blur(gray, edge, Size(3, 3));

	//运行canny算子
	Canny(edge, edge, 3, 9, 3);

	//将g_dstImage内的所有元素设置为0
	dst = Scalar::all(0);

	//使用canny算子输出的边缘图g_cannyDetectedEdges作为掩码，来将原图g_srcImage拷到目标图g_dstImage中
	src.copyTo(dst, edge);

	//显示效果图
	imshow("【灰度图】灰度canny检测图", edge);
	imshow("【效果图】canny边缘检测2", dst);
	waitKey(0);
	return 0;
}