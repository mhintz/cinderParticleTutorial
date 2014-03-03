#include "cinder/app/AppNative.h"
#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"

#include "Util.h"
#include "ParticleController.h"

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
    Color screenColor;
    gl::Texture myImage;
    ParticleController mParticleController;
private:
    const Vec2i imgDim = Vec2i( 197, 256 );
    const int imgMult = 3;
};

void TestCinderProjectApp::prepareSettings( Settings* settings ) {
    settings->setWindowSize( imgDim.x * imgMult, imgDim.y * imgMult );
    settings->setFrameRate( 60.0f );
}

void TestCinderProjectApp::setup() {
    screenColor = randColor();
    myImage = gl::Texture( loadImage( loadResource( "lilbub.jpeg") ) );
    mParticleController.addParticles( 20000 );
}

void TestCinderProjectApp::mouseDown( MouseEvent event ) {
    screenColor = randColor();
    console() << screenColor << std::endl;
}

void TestCinderProjectApp::mouseMove( MouseEvent event ) {

}

void TestCinderProjectApp::update() {
    mParticleController.update();
}

void TestCinderProjectApp::draw() {
    float shade = sin( getElapsedSeconds() ) * 0.5f + 0.5f;
	// clear out the window with black
	gl::clear( Color( shade * screenColor.r, shade * screenColor.g, shade * screenColor.b ) );
    if (myImage) {
        gl::draw( myImage, getWindowBounds() );
    }
    Vec2i winSz = getWindowSize();
    float x = cos( getElapsedSeconds() ) * 100.0f + winSz.x / 2;
    float y = sin( getElapsedSeconds() ) * 200.0f + winSz.y / 2;
    gl::drawSolidCircle( Vec2f(x, y), abs( y / x * 50), 7 );
    
    mParticleController.draw();
}

CINDER_APP_NATIVE( TestCinderProjectApp, RendererGl );



