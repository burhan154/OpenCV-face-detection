//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//           SAKARYA UNIVERSITESI BILGISAYAR MUHENDISLIGI
//						BITIRME CALISMASI
//                          2022/2023
//
//				  	 Hüseyin Burhan Basaran 			  
//					 	   G191210077 
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#ifndef Screen_hpp
#define Screen_hpp


#include<string>
#include <opencv2\opencv.hpp>
#include <opencv2\core.hpp>
#include <opencv2\highgui.hpp>
#include <opencv2\videoio.hpp>
#include "CvControl.hpp"

using namespace std;
using namespace cv;

class Screen
{
private:
	int frameCounter;
    int frameSize;
    CvControl controller;
public:
    Screen();
    Screen(int frame);
    int start();
    //Mat detectFaces(Mat & frame);
    //void overlayImage(const Mat &background, const Mat &foreground, Mat &output, Point2i location);
};


#endif