#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>


using namespace cv;
using namespace std;




/// //////////////// Images ///////////////


float w = 250, h = 350;
Mat matrix, matrixQ, matrixJ, matrix9, imgWarp, imgWarpQ, imgWarpJ, imgWarp9;


void main() {



	string path = "Resources/cards.jpg";
	Mat img = imread(path);

	//Source and Destination for King Card on image,
	Point2f src[4] = { {529,142},{771,190},{405,395},{674,457}};
	Point2f dst[4] = { {0.0f,0.0f},{w,0.0f},{0.0f,h},{w,h}};

	//Source and Destination for Queen Card on image, tl = {63, 324} tr = {340,280} bl = {90, 632} br = {400, 570}
	Point2f srcQ[4] = { {63, 324}, {340,280}, {90, 632}, {400, 570} };
	Point2f dstQ[4] = { {0.0f,0.0f},{w,0.0f},{0.0f,h},{w,h} };

	//Source and Destination for Jack Card on image, tl = {780,107} tr = {1024,80}  bl = {850, 355}  br = {1110, 330}
	Point2f srcJ[4] = { {780,107}, {1024,80}, {850, 355}, {1110, 330} };
	Point2f dstJ[4] = { {0.0f,0.0f},{w,0.0f},{0.0f,h},{w,h} };


	//Source and Destination for 9 Card on image, tl = {740,385} tr = {1020,438}  bl = {648,705}  br = {964,780}
	Point2f src9[4] = { {740,385}, {1020,438}, {648,705}, {964,780} };
	Point2f dst9[4] = { {0.0f,0.0f},{w,0.0f},{0.0f,h},{w,h} };

	matrix = getPerspectiveTransform(src, dst);
	matrixQ = getPerspectiveTransform(srcQ, dstQ);
	matrixJ = getPerspectiveTransform(srcJ, dstJ);
	matrix9 = getPerspectiveTransform(src9, dst9);

	warpPerspective(img, imgWarp, matrix, Point(w, h));
	warpPerspective(img, imgWarpQ, matrixQ, Point(w, h));
	warpPerspective(img, imgWarpJ, matrixJ, Point(w, h));
	warpPerspective(img, imgWarp9, matrix9, Point(w, h));

	for (int i = 0; i < 4; i++) {
		circle(img, src[i], 10, Scalar(0, 0, 255), FILLED);
		circle(img, srcQ[i], 10, Scalar(0, 0, 255), FILLED);
		circle(img, srcJ[i], 10, Scalar(0, 0, 255), FILLED);
		circle(img, src9[i], 10, Scalar(0, 0, 255), FILLED);

	}



	imshow("Image", img);
	imshow("Image Warp", imgWarp);
	imshow("Image WarpQ", imgWarpQ);
	imshow("Image WarpJ", imgWarpJ);
	imshow("Image Warp9", imgWarp9);

	waitKey(0);


}