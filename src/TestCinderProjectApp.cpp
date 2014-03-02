#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class TestCinderProjectApp : public AppNative {
  public:
    void prepareSettings( Settings* settings );
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
};

void TestCinderProjectApp::prepareSettings( Settings* settings ) {
    settings->setWindowSize( 800, 600 );
    settings->setFrameRate( 60.0f );
}

void TestCinderProjectApp::setup() {
}

void TestCinderProjectApp::mouseDown( MouseEvent event ) {
}

void TestCinderProjectApp::update() {
}

void TestCinderProjectApp::draw() {
	// clear out the window with black
	gl::clear( Color( 19, 220, 106 ) );
}

CINDER_APP_NATIVE( TestCinderProjectApp, RendererGl )
