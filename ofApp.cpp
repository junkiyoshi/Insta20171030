#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetFrameRate(60);
	ofBackground(0);
	ofSetWindowTitle("Insta");

	ofSetCircleResolution(32);

	this->box2d.init();
	this->box2d.setGravity(0, 20);
	this->box2d.createBounds();
	this->box2d.setFPS(60);
	this->box2d.registerGrabbing();
}

//--------------------------------------------------------------
void ofApp::update() {
	if (ofGetFrameNum() % 90 == 0) {
		float radius = 10;
		for (int i = 0; i < 5; i++) {
			float color_value = ofRandom(256);
			for (int deg = 0; deg < 360; deg += 10) {
				float x = radius * cos(deg * DEG_TO_RAD);
				float y = radius * sin(deg * DEG_TO_RAD);

				this->circles.push_back(shared_ptr<ofxBox2dCircle>(new ofxBox2dCircle));
				this->circles.back().get()->setPhysics(3.0, 0.5, 0.1);
				this->circles.back().get()->setup(this->box2d.getWorld(), ofGetWidth() / 2 + x, ofGetHeight() / 5 + y, 5);
				this->circles.back().get()->addForce(ofVec2f(x, y), 4.0);

				ofColor circle_color;
				circle_color.setHsb(color_value, 255, 255);
				this->circles_color.push_back(circle_color);
			}

			radius += 10;
		}
	}

	this->box2d.update();
}

//--------------------------------------------------------------
void ofApp::draw() {
	for (int i = 0; i < this->circles.size(); i++) {
		ofSetColor(this->circles_color[i]);
		ofDrawCircle(this->circles[i].get()->getPosition().x, this->circles[i].get()->getPosition().y, 5);
	}

	ofImage image;
	image.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
	image.saveImage(to_string(ofGetFrameNum()) + ".png");
}

//--------------------------------------------------------------
int main() {
	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}