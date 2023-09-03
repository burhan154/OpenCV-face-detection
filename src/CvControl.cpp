//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//           SAKARYA UNIVERSITESI BILGISAYAR MUHENDISLIGI
//						BITIRME CALISMASI
//                          2022/2023
//
//				  	 Hüseyin Burhan Basaran 			  
//					 	   G191210077 
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


#include <iostream>
#include <string>
#include <opencv2\opencv.hpp>
#include <opencv2\core.hpp>
#include <opencv2\highgui.hpp>
#include <opencv2\videoio.hpp>
#include "CvControl.hpp"
#include "Processes.hpp"

using namespace cv;
using namespace std;


int CvControl::show(string windowName){
	//imshow(windowName, frame);
    imshow(windowName, process.butterflyFilter(frame));
    return 1;
}

int CvControl::startImage(string path, string windowName){
	int key = 0;
	while (key != 'q') {
		frame = imread(path);
        show(windowName);
		key = waitKey(1);
	}
	destroyWindow(windowName);
	return 0;
}

int CvControl::startVideo(string path, string windowName){
	VideoCapture capture;
	string str;
	int key = 0;
    if(path==""){
        capture.open(0);
    }else{
        capture.open(path);
    }
    if (!capture.isOpened())
	{
		cerr << "Error opening video file!\n";
		return 0;
	}
	video.width = (int)capture.get(cv::CAP_PROP_FRAME_WIDTH);
	video.height = (int)capture.get(cv::CAP_PROP_FRAME_HEIGHT);

	//int frame_counter = 0;

	namedWindow(windowName, cv::WINDOW_AUTOSIZE);
	uchar fillValue = 128;
	while (key != 'q') {
		capture.read(frame);
		
		// if (frame_counter == capture.get(CAP_PROP_FRAME_COUNT)) {
		// 	frame_counter=0;
		// 	capture.set(CAP_PROP_POS_FRAMES,0);
		// }
		if (frame.empty()) break;
		
		//cout<< capture.get(CAP_PROP_FRAME_COUNT);
        show(windowName);
		//frame_counter++;
		key = waitKey(1);
	}
	destroyWindow(windowName);
	capture.release();
    return 1;
}

int CvControl::startCamera(string windowName){
    return startVideo("",windowName);;
}