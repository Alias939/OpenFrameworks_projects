#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	ofSetFrameRate(60);
	ofSetWindowTitle("openframeworks");

	ofBackground(239);
	ofSetLineWidth(2);
	ofNoFill();
	ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_MULTIPLY);

	x, y = 0;
	radius_const = 75;
	span = 2;

}

//--------------------------------------------------------------
void ofApp::update(){
	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw(){

		ofTranslate(ofGetWidth() * 0.5, ofGetHeight() * 0.5);

		vector<ofColor> color_list = { ofColor(255, 0, 0), ofColor(0, 255, 0), ofColor(0, 0, 255) };
		for (int i = 0; i < span; i++) {

			auto radius = radius_const + i * radius_const;
			//auto rotate_deg = (ofGetFrameNum() + i * 180) % 360;


			//auto x = ((ofGetMouseX() * 1.0 / ofGetWidth())* 360 ) - 90;

			auto x = ofGetMouseX() * 1.0 - ofGetWidth() * 0.5;
			auto y = ofGetMouseY() * 1.0 - ofGetHeight() * 0.5;
			//ofLog(OF_LOG_NOTICE, "the number is " + ofToString(rotate_deg));

			auto rotate_deg = 0.0;

			
			rotate_deg = atan(y / x);


			rotate_deg = rotate_deg * (180 / PI);

			if (x < 0)
			{
				rotate_deg += 180;
			}
			
			//ofLog(OF_LOG_NOTICE, "the number is " + ofToString(rotate_deg));

			auto rotate_location = glm::vec2(radius * cos(rotate_deg * DEG_TO_RAD), radius * sin(rotate_deg * DEG_TO_RAD));

			for (int k = 0; k < color_list.size(); k++) {

				auto noise_seed = ofRandom(1000);

				ofSetColor(color_list[k]);
				ofBeginShape();
				for (int deg = 0; deg < 360; deg += 1) {

					auto location = glm::vec2(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD));
					auto distance = glm::distance(location, rotate_location);
					if (distance < radius * 0.75) {

						auto noise_radius = ofMap(ofNoise(noise_seed, location.x * 0.035, location.y * 0.035, ofGetFrameNum() * 0.005), 0, 1, radius - radius_const, radius + radius_const);
						auto noise_location = glm::vec2(noise_radius * cos(deg * DEG_TO_RAD), noise_radius * sin(deg * DEG_TO_RAD));
						auto gap = location - noise_location;
						ofVertex(location + gap * ofMap(distance, 0, radius * 0.75, 1, 0));
					}
					else {

						ofVertex(location);
					}
				}
				ofEndShape(true);
			}
		}
	}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){

	if (key == OF_KEY_UP)
	{
		radius_const++;

	}
	if (key == OF_KEY_DOWN)
	{
		radius_const--;
	}
	if (key == OF_KEY_LEFT)
	{
		span--;
		if (span<1)
		{
			span = 1;
		}

	}
	if (key == OF_KEY_RIGHT)
	{
		span++;
	}

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
