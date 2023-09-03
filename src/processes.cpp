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
#include "Processes.hpp"

using namespace cv;
using namespace std;

Processes::Processes(){
	face_cascade = CascadeClassifier("data/haarcascade_frontalface_default.xml");

	imgSize = 5;
	frameSize=24;
	frameCounter =0;

	for(int i = 1; i<=imgSize;i++){
		Mat gifImage = imread("data/butterfly/" + to_string(i) + ".png",-1);
		gif.push_back(gifImage);
	}
}


Mat Processes::butterflyFilter(Mat & frame){
    face_cascade.detectMultiScale(frame,faces,1.2,5,0,Size(120,120),Size(350,350));
	for(int i = 0; i<faces.size();i++){
		if(faces[i].x>0 &&faces[i].y>0){
			Mat imgNew;
			
			int x =faces[i].x;
			if(frameCounter/12){
				x += faces[i].width/10;
			}
			else{
				x += faces[i].width/5;
			}

			resize(gif[frameCounter/(imgSize)], imgNew, Size(faces[i].height/3, faces[i].width/3));
			overlayImage(frame, imgNew, frame, Point(x, faces[i].y));

			if(i==faces.size()-1){
				frameCounter++;
				if(frameCounter==frameSize){
					frameCounter=0;
				}
			}
			
		}
	}	
    return frame;
}

Mat Processes::detectFaces(Mat & frame){
    face_cascade.detectMultiScale(frame,faces,1.2,5,0,Size(120,120),Size(350,350));
	for(int i = 0; i<faces.size();i++){
		rectangle(frame,faces[i].tl(), faces[i].br(),Scalar(50,50,255),3);
	}
    return frame;
}

void Processes::overlayImage(const Mat &background, const Mat &foreground, Mat &output, Point2i location)
{
	background.copyTo(output);
	for(int y = std::max(location.y , 0); y < background.rows; ++y)
	{
		int fY = y - location.y; 

		if(fY >= foreground.rows)
		break;

		for(int x = std::max(location.x, 0); x < background.cols; ++x)
		{
			int fX = x - location.x; 

			if(fX >= foreground.cols)
				break;

			double opacity = ((double)foreground.data[fY * foreground.step + fX * foreground.channels() + 3]) / 255.;
			for(int c = 0; opacity > 0 && c < output.channels(); ++c)
			{
				unsigned char foregroundPx =foreground.data[fY * foreground.step + fX * foreground.channels() + c];
				unsigned char backgroundPx =background.data[y * background.step + x * background.channels() + c];
				output.data[y*output.step + output.channels()*x + c] = backgroundPx * (1.-opacity) + foregroundPx * opacity;
			}
		}
	}
}



