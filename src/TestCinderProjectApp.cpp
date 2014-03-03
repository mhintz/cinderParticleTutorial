#include "cinder/app/AppNative.h"
#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"
#include "cinder/Channel.h"

#include "Util.h"
#include "ParticleController.h"

#define RESOLUTION 5

using namespace ci;
using namespace ci::app;
using namespace std;

class TestCinderProjectApp : public AppNative {
public:
    void prepareSettings( Settings* settings );
	void setup();
	void mouseDown( MouseEvent event );
    void mouseMove( MouseEvent event );
	void update();
	void draw();
    ParticleController mParticleController;
    Channel32f mChannel;
};

void TestCinderProjectApp::prepareSettings( Settings* settings ) {
    settings->setWindowSize( 197, 256 );
    settings->setFrameRate( 60.0f );
}

void TestCinderProjectApp::setup() {
    mParticleController = ParticleController( RESOLUTION );
    mChannel = Channel32f ( loadImage ( loadResource( "lilbub.jpeg" ) ) );
}

void TestCinderProjectApp::mouseDown( MouseEvent event ) {

}

void TestCinderProjectApp::mouseMove( MouseEvent event ) {

}

void TestCinderProjectApp::update() {
    mParticleController.update( mChannel );
}

void TestCinderProjectApp::draw() {
	// clear out the window with black
	gl::clear( Color( 0.0f, 0.0f, 0.0f ) );
    
    mParticleController.draw();
}

CINDER_APP_NATIVE( TestCinderProjectApp, RendererGl );



