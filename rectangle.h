/*Author : Savita Seetaraman
 * Date : November 20th, 2013
 */


#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

extern int threshold_value;

vector <vector < Point> > contourExtraction (Mat& src);
int rectangleDetection (Mat & imageROI, vector <vector <Point> > contours);

#endif
