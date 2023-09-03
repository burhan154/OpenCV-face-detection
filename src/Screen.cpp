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
#include "Screen.hpp"

using namespace cv;
using namespace std;

Screen::Screen(){
	frameSize=30;
	frameCounter = 0;
}

Screen::Screen(int frame){
	frameSize=frame;
	frameCounter = 0;
}

int Screen::start(){
	//controller.startCamera("Camera Screen");
	//controller.startImage("data/test.jpg","Image Screen");
	controller.startVideo("data/test.mp4","Video Screen");
    return 1;
}





