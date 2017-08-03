// ����opencv����canny��Ե��⡣
// ����ͼ�񣬲�����ת�ɻҶ�ͼ������blur��������ͼ��ģ���Խ��룬
// Ȼ����canny�������б�Ե��⣬�����ʾ��

#include <opencv2\opencv.hpp>
#include <opencv2\imgproc\imgproc.hpp>
using namespace cv; //����CV�����ռ�

int main() 
{
	// load image
	Mat srcImage = imread("D:/ex/vsprojects/test_opencv_install/canny_bianyuanjiance/2.jpg");
	imshow("��ԭʼͼ��canny��Ե���", srcImage);
	Mat dstImage, edge, grayImage; //�����������������

	// ������srcͬ���ͺʹ�С�ľ���(dst)
	dstImage.create(srcImage.size(), srcImage.type());

	//��ԭʼͼת��Ϊ�Ҷ�ͼ
	cvtColor(srcImage, grayImage, COLOR_BGR2GRAY);

	//��ʹ��3X3�ں�������
	//blur(grayImage, edge, Size(10, 10));

	//����canny����
	Canny(edge, edge, 6, 20, 3);

	//��ʾЧ��
	imshow("��Ч��ͼ��canny��Ե���", edge);
	waitKey(0);
	return 0;
}