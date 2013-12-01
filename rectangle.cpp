/*Author : Savita Seetaraman,
 * Date : November 18th, 2013
 */

#include "rectangle.h"

int const max_BINARY_value = 255;
int houghthresh = 40;
int threshold_type = 0;

vector <vector < Point> > contourExtraction (Mat& src) {
	Mat gray_dst, threshold_dst, dilate_dst;
	vector <vector <Point> > contours;

	//Image is being processed

	cvtColor(src, gray_dst, CV_BGR2GRAY);
	threshold(gray_dst, threshold_dst, threshold_value, max_BINARY_value,threshold_type );
	dilate(threshold_dst, dilate_dst,  Mat(),  Point(-1,-1));
	dilate(dilate_dst, dilate_dst,  Mat(),  Point(-1,-1));
	dilate(dilate_dst, dilate_dst,  Mat(),  Point(-1,-1));

	//Size of the image is reduced to extract only the necessary information.

	Rect ROI1 (0, 315, 640, 160);
	Mat imageROI (dilate_dst, ROI1);

	//Contours of the image are found.

	findContours(imageROI, contours, CV_RETR_LIST, CV_CHAIN_APPROX_SIMPLE);
	imageROI.copyTo(src);

	return contours;
}

int rectangleDetection (Mat & imageROI, vector <vector <Point> > contours) {
	int x = 0;
	vector <Point> approx;
	for (unsigned int i=0; i<contours.size(); i++) {

		//Approximation of the contours according to the precision specified.
		approxPolyDP( Mat(contours[i]), approx,  arcLength( Mat(contours[i]), true)*0.03, true);

		//Detection of rectangles with the following conditions.
	    if (approx.size() == 4 && (fabs(contourArea(Mat(approx)))) > 200 && arcLength(Mat(contours[i]), true) > 40
	    	&& (fabs(contourArea(Mat(approx)))) < 10000 && isContourConvex(Mat(approx))) {
	    	cout << "Amma please..." << endl;
	    	line (imageROI, approx[0], approx[1], Scalar(255, 0, 0), 1, 8);
	    	line (imageROI, approx[2], approx[3], Scalar(255, 0, 0), 1, 8);
	    	line (imageROI, approx[0], approx[2], Scalar(255, 0, 0), 1, 8);
	    	line (imageROI, approx[1], approx[3], Scalar(255, 0, 0), 1, 8);
	    	x += 1;
	    }
	}

	//Returns the number of rectangles detected.
	return x;
}
