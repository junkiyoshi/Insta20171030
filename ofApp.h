#pragma once

#include <Windows.h>
#include <NuiApi.h>
#include <opencv2/opencv.hpp>
#include "ofMain.h"

#ifdef _DEBUG
#pragma comment(lib,"opencv_calib3d310d.lib")
#pragma comment(lib,"opencv_core310d.lib")
#pragma comment(lib,"opencv_features2d310d.lib")
#pragma comment(lib,"opencv_flann310d.lib")
#pragma comment(lib,"opencv_highgui310d.lib")
#pragma comment(lib,"opencv_imgcodecs310d.lib")
#pragma comment(lib,"opencv_imgproc310d.lib")
#pragma comment(lib,"opencv_ml310d.lib")
#pragma comment(lib,"opencv_objdetect310d.lib")
#pragma comment(lib,"opencv_photo310d.lib")
#pragma comment(lib,"opencv_shape310d.lib")
#pragma comment(lib,"opencv_stitching310d.lib")
#pragma comment(lib,"opencv_superres310d.lib")
#pragma comment(lib,"opencv_video310d.lib")
#pragma comment(lib,"opencv_videoio310d.lib")
#pragma comment(lib,"opencv_videostab310d.lib")
#else
#pragma comment(lib,"opencv_calib3d310.lib")
#pragma comment(lib,"opencv_core310.lib")
#pragma comment(lib,"opencv_features2d310.lib")
#pragma comment(lib,"opencv_flann310.lib")
#pragma comment(lib,"opencv_highgui310.lib")
#pragma comment(lib,"opencv_imgcodecs310.lib")
#pragma comment(lib,"opencv_imgproc310.lib")
#pragma comment(lib,"opencv_ml310.lib")
#pragma comment(lib,"opencv_objdetect310.lib")
#pragma comment(lib,"opencv_photo310.lib")
#pragma comment(lib,"opencv_shape310.lib")
#pragma comment(lib,"opencv_stitching310.lib")
#pragma comment(lib,"opencv_superres310.lib")
#pragma comment(lib,"opencv_video310.lib")
#pragma comment(lib,"opencv_videoio310.lib")
#pragma comment(lib,"opencv_videostab310.lib")
#endif

class ofApp : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key) {}
	void keyReleased(int key) {}
	void mouseMoved(int x, int y) {}
	void mouseDragged(int x, int y, int button) {}
	void mousePressed(int x, int y, int button) {}
	void mouseReleased(int x, int y, int button) {}
	void mouseEntered(int x, int y) {}
	void mouseExited(int x, int y) {}
	void windowResized(int w, int h) {}
	void dragEvent(ofDragInfo dragInfo) {}
	void gotMessage(ofMessage msg) {}

	// Kinect
	INuiSensor* sensor;
	INuiCoordinateMapper* cordinate_mapper;
	HANDLE color_event;
	HANDLE color_handle;
	HANDLE depth_event;
	HANDLE depth_handle;
	HANDLE events[2];
	int width, height;

	// OpenCV
	cv::Mat frame;
	cv::Mat depth;
	cv::Mat depth_log[7];

	// openFrameworks
	ofEasyCam cam;
	ofImage frame_img;
	vector<ofVec3f> locations;
	vector<ofColor> colors;
};
