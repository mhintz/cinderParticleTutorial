//
//  Particle.cpp
//  TestCinderProject
//
//  Created by Mark Hintz on 2/3/14.
//
//

#include "Particle.h"

#include "cinder/Rand.h"

using namespace ci;

Particle::Particle() {
}

Particle::Particle( Vec2f loc ) {
    mLoc = loc;
    mDir = Rand::randVec2f();
    mVel = Rand::randFloat( 5.0f );
//    mRadius = Rand::randFloat( 1.0f, 5.0f );
//    mRadius = cos ( mLoc.y * 0.1f ) + sin( mLoc.x * 0.1f ) + 2.0f;
//    mRadius = (sin( mLoc.y * mLoc.x ) + 1.0f) * 2.0f;
//    float xyOffset = sin( cos( sin( mLoc.y * 0.3183f ) + cos( mLoc.x * 0.3183f ) ) ) + 1.0f;
//    mRadius = xyOffset * xyOffset * 1.8f;
    mRadius = 2.5f;
    mColor = Color( 1.0f, 1.0f, 1.0f );
}

void Particle::update() {
    mLoc += mDir * mVel;
}

void Particle::update( const Channel32f & channel ) {
//    float grey = channel.getValue( mLoc );
//    mColor = Color( grey, grey, grey );
    mRadius = channel.getValue( mLoc ) * 4.0f;
}

void Particle::draw() {
    gl::color( mColor );
    
    float time = app::getElapsedSeconds();
    
    gl::drawSolidCircle( mLoc, mRadius - cos( time ) * mRadius / 4.0f );
}