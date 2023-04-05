#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>


using namespace cv;
using namespace std;

///////// 144, 175, 117 , 255 , 121, 211  //////// purple
///////// 57, 83, 36, 196, 56, 160 ////////// Green
////// green retry, 61,99,75,255,40,70
//// green 76,113,0,199,33,103

/// ////////////////Importing Images //////////////

Mat imgHSV, mask, imgColor;
int hmin = 0, smin = 0, vmin = 0;
int hmax = 179, smax = 255, vmax = 255;

VideoCapture cap(0);
Mat img;

void main() {

	string path = "Resources/shapes.png";


	namedWindow("Trackbars", WINDOW_AUTOSIZE);
	createTrackbar("Hue Min", "Trackbars", &hmin, 179);
	createTrackbar("Hue Max", "Trackbars", &hmax, 179);
	createTrackbar("Sat Min", "Trackbars", &smin, 255);
	createTrackbar("Sat Max", "Trackbars", &smax, 255);
	createTrackbar("Val Min", "Trackbars", &vmin, 255);
	createTrackbar("Val Max", "Trackbars", &vmax, 255);


	while (true) {
		cap.read(img);
		cvtColor(img, imgHSV, COLOR_BGR2HSV);

	
		Scalar lower(hmin, smin, vmin);
		Scalar upper(hmax, smax, vmax);
		inRange(imgHSV, lower, upper, mask);

		imshow("Image", img);
		imshow("Image Mask", mask);
		waitKey(1);
	}


}