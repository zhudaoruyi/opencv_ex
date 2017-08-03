#include <opencv2\opencv.hpp>
using namespace cv;

int main()
{
	// ������ͷ������Ƶ
	VideoCapture capture(0);
	Mat edges;

	// ѭ����ʾÿһ֡
	while (1)
	{
		Mat frame; //����һ��Mat���������ڴ洢ÿһ֡��ͼ��
		capture >> frame; //��ȡ��ǰ֡

		// �Ҷȴ���
		cvtColor(frame, edges, CV_BGR2GRAY);

		//����
		blur(edges, edges, Size(7, 7));

		//����canny��Ե��Ⲣ��ʾ
		Canny(edges, edges, 0, 30, 3);
		imshow("��ȡcanny�����Ƶ", edges); //��ʾ

		if(waitKey(300)>=0) break; //��ʱ 30ms
	}
	imshow("result", edges);
	waitKey(0);
	return 0;
}