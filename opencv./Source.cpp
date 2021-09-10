#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace cv;
using namespace std;


int main(int argc, char** argv)
{

	int height = 520;
	int width = 840;
	Mat img(height, width, CV_8UC3);

		Point textOrg(100, img.rows / 2);
		int fontFace = FONT_HERSHEY_SCRIPT_SIMPLEX;
		double fontScale = 2;
		Scalar color(200, 100, 50);
			putText(img, "OpenCV step By Step", textOrg, fontFace, fontScale, color);
			
			imshow("Hello World", img);

			Mat imgt = imread("read.jpg", 1);
			imshow("Load", imgt);
			waitKey(0);
			system("pause");

			return 0;
		
}



