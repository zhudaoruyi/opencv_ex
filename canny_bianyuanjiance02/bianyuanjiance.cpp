#include <opencv2\opencv.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>
using namespace cv;

int main()
{
	// ����ԭʼͼ
	Mat src = imread("D:/ex/vsprojects/test_opencv_install/canny_bianyuanjiance/mt.jpg");
	Mat src1 = src.clone();

	// ��ʾԭʼͼ
	imshow("��ԭʼͼ��canny��Ե���", src);

	//--------------------------------------------------
	// ����һ����򵥵�canny�÷����õ�ԭͼ��ֱ���á�
	// ע�⣺�η�����opencv2�п��ã���opencv3���Ѿ�ʧЧ
	//--------------------------------------------------
	//Canny(srcImage,srcImage,150,100,3);
	//imshow("��Ч��ͼ��canny��Ե���",srcImage);

	//--------------------------------------------------
	//���������߽׵�canny�÷���ת�ɻҶ�ͼ�����룬��canny����󽫵õ��ı�Ե��Ϊ���룬����ԭͼ��Ч��ͼ�ϣ��õ���ɫ�ı�Եͼ
	//--------------------------------------------------
	Mat dst, edge, gray;

	//������srcͬ���ͺʹ�С�ľ���dst��
	dst.create(src1.size(), src1.type());

	//��ԭͼ��תΪ�Ҷ�ͼ��
	cvtColor(src1, gray, COLOR_BGR2GRAY);

	//����3X3�ں�������
	blur(gray, edge, Size(3, 3));

	//����canny����
	Canny(edge, edge, 3, 9, 3);

	//��g_dstImage�ڵ�����Ԫ������Ϊ0
	dst = Scalar::all(0);

	//ʹ��canny��������ı�Եͼg_cannyDetectedEdges��Ϊ���룬����ԭͼg_srcImage����Ŀ��ͼg_dstImage��
	src.copyTo(dst, edge);

	//��ʾЧ��ͼ
	imshow("���Ҷ�ͼ���Ҷ�canny���ͼ", edge);
	imshow("��Ч��ͼ��canny��Ե���2", dst);
	waitKey(0);
	return 0;
}