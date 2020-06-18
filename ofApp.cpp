#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);
	ofSetColor(39);

	ofSetRectMode(ofRectMode::OF_RECTMODE_CENTER);
	this->noise_param = ofRandom(1000);
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	int x_span = 10;
	int y_span = 180;
	int height = 60;
	for (int x = x_span * 3; x <= ofGetWidth() - x_span * 3; x += x_span) {

		for (int y = y_span; y < ofGetHeight(); y += y_span) {

			auto noise_value = ofNoise(x * 0.02, y * 0.02, this->noise_param);

			if (noise_value < 0.5) {

				ofDrawRectangle(glm::vec2(x, y - ofMap(noise_value, 0, 0.5, height * 0.5, 0)), x_span * 0.8, ofMap(noise_value, 0, 0.5, height, 0));
			}
			else {

				ofDrawRectangle(glm::vec2(x, y + ofMap(noise_value, 0.5, 1, 0, height * 0.5)), x_span * 0.8, ofMap(noise_value, 0.5, 1, 0, height));
			}
		}
	}

	if (ofGetFrameNum() % 60 < 45) {

		this->noise_param += ofMap(ofGetFrameNum() % 60, 0, 45, 0.05, 0);
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}
