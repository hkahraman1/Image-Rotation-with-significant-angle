#include<opencv2/core.hpp>
#include<opencv2/imgproc.hpp>
#include<opencv2/highgui.hpp>
#include<iostream>

using namespace cv;
using namespace std;

int main()
{
	Mat resim = imread("sample1.jpg");
	resize(resim, resim, Size(400, 400));
	Mat cikis;
	Point2f kordinat(resim.rows / 2, resim.cols / 2);
	int aci = 0;
	for (;;)
	{
		cout << "aci" << aci << endl;
		Mat dondurme = getRotationMatrix2D(kordinat, aci, 1);
		Rect2f kutu = RotatedRect(Point2f(), resim.size(), aci).boundingRect2f();
		dondurme.at<double>(0, 2) += (kutu.width / 2 - resim.cols / 2);
		dondurme.at<double>(1, 2) += (kutu.height / 2 - resim.rows / 2);
		warpAffine(resim, cikis, dondurme, kutu.size());
		imshow("dondurulmus", cikis);
		waitKey(1000);
		aci += 45;
		if (aci > 360) {
			break;
		}
	}

}
