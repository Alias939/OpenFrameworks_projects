#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	ofSetFrameRate(60);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);
	ofSetLineWidth(2);

	mode = 1;
	radius = 200;
	intensity = 0.0001;

}

//--------------------------------------------------------------
void ofApp::update(){


	
}

//--------------------------------------------------------------
void ofApp::draw(){
	
	if (radius<0)
	{
		radius = 0;
	}


	if (mode == 1)
	{
		int span = 12; //distance between lines
		for (int y = span * -5; y < ofGetHeight() + span * 5; y += span) {  //parcurge putin inainte si dupa ecran

			vector<glm::vec2> vertices;			//vert unei linii
			vertices.push_back(glm::vec2(0, ofGetHeight()));		//initial 0,maxh
			for (int x = 0; x <= ofGetWidth(); x += 5) {		//de la stanga la dr pe o linie

				auto distance = sqrt(abs(ofGetMouseX() - x) * abs(ofGetMouseX() - x) + abs(ofGetMouseY() - y) * abs(ofGetMouseY() - y));		//distanta fata de centru / mousex / mousey
				auto tmp_y = 0.f;       // initial y noise

				if (distance < radius) {			//cat de mult in fiecare directie 


					float noise_value = 0;
					if (y > ofGetMouseY())
					{
						noise_value = (ofGetMouseY()- y) * (ofGetMouseY() - y) * intensity;
						auto param = ofMap(distance, 0, radius, 1, 0);
						tmp_y = ofMap(noise_value, -1, 1, span * -5 * param, span * 5 * param);
						
					}
					else
					{
						noise_value = -abs(ofGetMouseY() - y) * abs(ofGetMouseY() - y) * intensity;
						auto param = ofMap(distance, 0, radius, -1, 0);
						tmp_y = ofMap(noise_value, 1, -1, span * -5 * param, span * 5 * param);
						
					}

					//auto noise_value = ofNoise(y * 0.03, x * 0.01, ofGetFrameNum() * 0.005);
					
				}

				vertices.push_back(glm::vec2(x, y + tmp_y));
			}
			vertices.push_back(glm::vec2(ofGetWidth(), ofGetHeight()));

			ofFill();
			ofSetColor(239);
			ofBeginShape();
			ofVertices(vertices);
			ofEndShape(true);

			ofNoFill();
			ofSetColor(39);
			ofBeginShape();
			ofVertices(vertices);
			ofEndShape(true);
		}

	}

	if (mode == -1)
	{
		int span = 12; //distance between lines
		

		for (int y = span * -5; y < ofGetHeight() + span * 5; y += span) {  //parcurge putin inainte si dupa ecran

			vector<glm::vec2> vertices;			//vert unei linii
			vertices.push_back(glm::vec2(0, ofGetHeight()));		//initial 0,maxh
			for (int x = 0; x <= ofGetWidth(); x += 5) {		//de la stanga la dr pe o linie

				auto distance = sqrt(abs(ofGetMouseX() - x) * abs(ofGetMouseX() - x) + abs(ofGetMouseY() - y) * abs(ofGetMouseY() - y));		//distanta fata de centru / mousex
				auto tmp_y = 0.f;

				if (distance < radius) {			//cat de mult in fiecare directie 

					auto noise_value = ofNoise(y * 0.03, x * 0.01, ofGetFrameNum() * 0.005);
					auto param = ofMap(distance, 0, radius, 1, 0);
					tmp_y = ofMap(noise_value, 0, 1, span * -5 * param, span * 5 * param);
				}

				vertices.push_back(glm::vec2(x, y + tmp_y));
			}
			vertices.push_back(glm::vec2(ofGetWidth(), ofGetHeight()));

			ofFill();
			ofSetColor(239);
			ofBeginShape();
			ofVertices(vertices);
			ofEndShape(true);

			ofNoFill();
			ofSetColor(39);
			ofBeginShape();
			ofVertices(vertices);
			ofEndShape(true);
		}

	}

	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == ' ')
	{
		mode *= -1;
	}

	if (key == 'f')
	{
		ofToggleFullscreen();
	}

	if (key == OF_KEY_DOWN)
	{
		radius-=10;
	}
	if (key == OF_KEY_UP)
	{
		radius+=10;
	}

	if (key == OF_KEY_LEFT)
	{
		intensity -= 0.00001;
	}
	if (key == OF_KEY_RIGHT)
	{
		intensity += 0.00001;
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
