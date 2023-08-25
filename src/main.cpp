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
#include "CvControl.hpp"

using namespace std;

int main(){
	CvControl controller;
	//controller.startCamera("Camera Screen");
	controller.startImage("data/test.jpg","Image Screen");
	//controller.startVideo("data/test.mp4","Video Screen");
	return 0;
}
