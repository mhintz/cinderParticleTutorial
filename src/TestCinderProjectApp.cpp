#include "cinder/app/AppNative.h"
#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"
#include "cinder/Perlin.h"
#include "cinder/Channel.h"
#include "cinder/Vector.h"
#include "cinder/Utilities.h"

#include "Util.h"
#include "ParticleController.h"

#define RESOLUTION 10
#define NUM_PARTICLES_TO_SPAWN 15

using namespace ci;
using namespace ci::app;
using namespace std;

class TestCinderProjectApp : public AppNative {
public:
    void prepareSettings( Settings* );
	void setup();
	void update();
	void draw();

    void keyDown( KeyEvent );
	void mouseDown( MouseEvent );
    void mouseUp( MouseEvent );
    void mouseMove( MouseEvent );
    void mouseDrag( MouseEvent );
    
    Perlin mPerlin;
    
    Channel32f mChannel;
    gl::Texture mTexture;
    
    ParticleController mParticleController;
    
    Vec2i mMouseLoc;
    Vec2f mMouseVel;

    bool mousePressed;
    bool mDrawParticles;
    bool mDrawImage;
    bool mSaveFrames;
};

void TestCinderProjectApp::prepareSettings( Settings* settings ) {
    settings->setWindowSize( 800, 600 );
    settings->setFrameRate( 60.0f );
}

void TestCinderProjectApp::setup() {
    mPerlin = Perlin();
    
    Url catUrl( "http://libcinder.org/media/tutorial/paris.jpg" );
    mChannel = Channel32f ( loadImage ( loadUrl( catUrl ) ) );
    mTexture = mChannel;
    
    mMouseLoc = Vec2i( getWindowWidth() / 2, getWindowHeight() / 2 );
    mMouseVel = Vec2f::zero();
    mousePressed = false;
    
    mDrawParticles = true;
    mDrawImage = false;
    mSaveFrames = false;
}

void TestCinderProjectApp::mouseDown( MouseEvent event ) {
    mousePressed = true;
}

void TestCinderProjectApp::mouseUp( MouseEvent event ) {
    mousePressed = false;
}

void TestCinderProjectApp::mouseMove( MouseEvent event ) {
    mMouseVel = (event.getPos() - mMouseLoc);
    mMouseLoc = event.getPos();
}

void TestCinderProjectApp::mouseDrag( MouseEvent event ) {
    mouseMove(event);
}

void TestCinderProjectApp::keyDown( KeyEvent event ) {
    if (event.getChar() == '1') {
        mDrawImage = !mDrawImage;
    } else if (event.getChar() == '2') {
        mDrawParticles = !mDrawParticles;
    }
    
    if (event.getChar() == 's') {
        mSaveFrames = !mSaveFrames;
    }
}

void TestCinderProjectApp::update() {
    if (!mChannel) return;
    
    if (mousePressed) {
        mParticleController.addParticles( NUM_PARTICLES_TO_SPAWN, mMouseLoc, mMouseVel );
    }
    
    mParticleController.update( mChannel, mMouseLoc );
}

void TestCinderProjectApp::draw() {
	gl::clear( Color( 0.0f, 0.0f, 0.0f ), true );
    
    if ( mDrawImage ) {
        gl::draw( mTexture, getWindowBounds() );
    }
    
    if (mDrawParticles) {
        mParticleController.draw();
    }
}

CINDER_APP_NATIVE( TestCinderProjectApp, RendererGl );



