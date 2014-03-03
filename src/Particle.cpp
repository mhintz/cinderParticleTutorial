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
    mRadius = 3.0f;
}

void Particle::update() {
    mLoc += mDir * mVel;
}

void Particle::draw() {
    gl::drawSolidCircle( mLoc, mRadius );
}