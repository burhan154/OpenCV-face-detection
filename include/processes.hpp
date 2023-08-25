//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//           SAKARYA UNIVERSITESI BILGISAYAR MUHENDISLIGI
//						BITIRME CALISMASI
//                          2022/2023
//
//				  	 Hüseyin Burhan Basaran 			  
//					 	   G191210077 
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#ifndef Processes_hpp
#define Processes_hpp


#include<string>
#include <opencv2\opencv.hpp>
#include <opencv2\core.hpp>
#include <opencv2\highgui.hpp>
#include <opencv2\videoio.hpp>

using namespace std;
using namespace cv;

class Processes
{
private:
    vector<Rect> faces;
    CascadeClassifier face_cascade;
    vector<Mat> gif;
	int frameCounter;

    int frameSize;
    int imgSize;
public:
    Processes();
    Mat butterflyFilter(Mat &frame);
    Mat detectFaces(Mat & frame);
    void overlayImage(const Mat &background, const Mat &foreground, Mat &output, Point2i location);
};


#endif