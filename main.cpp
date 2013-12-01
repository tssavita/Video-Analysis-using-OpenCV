/*Author : Savita Seetaraman
 *Date : November 16th, 2013
 */

#include "rectangle.h"

int const max_value = 255;
int const max_type = 4;

char* window_name = "Parking spots are detected";
char* trackbar_value = "Value";

int threshold_value = 90;

int main(int argc, char** argv) {
	Mat src, image, dst;
	int x = 0;
	vector <vector <Point> > contours;
	namedWindow( window_name, CV_WINDOW_AUTOSIZE );
	createTrackbar( trackbar_value, window_name, &threshold_value, max_value);
	cout <<"Amma please help me..."<<endl;

	//Extracting the image from video.

	VideoCapture cap("../Parking 3.avi");
	for (int i = 0; i < 10000; i++) {
		x = 0;
		cap >> src;
		src.copyTo(image);

		//Processing the input image and extracting the contours from it.
		contours = contourExtraction(image);
		imshow("After processing and extracting contours", image);

		//Detecting rectangles from contours.
		x = rectangleDetection(image, contours);

		image.copyTo(dst);
		imshow(window_name, dst);
		imshow("src", src);
		waitKey(30);
	}

	cout <<"x = " << x <<endl;

	return 0;
}
