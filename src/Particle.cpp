//
//  Particle.cpp
//  TestCinderProject
//
//  Created by Mark Hintz on 2/3/14.
//
//

#include "Particle.h"

#include "cinder/Rand.h"
#include <math.h>

using namespace ci;

Vec2f GRAVITY = ci::Vec2f(0.0, -0.075);
float INITIAL_SPEED = 3.0f;
float DECAY = 0.99;

float RAD_MAX = 4.0f;
float RT_THREE = sqrt( 3.0f );

Particle::Particle() {}

Color randColor() {
    float r = Rand::randFloat();
    float g = Rand::randFloat();
    float b = Rand::randFloat();
    return Color(r, g, b);
}

class Triangle {
public:
    Triangle(Vec2f & center, float rad);
    
    Vec2f a;
    Vec2f b;
    Vec2f c;
};

Triangle::Triangle(Vec2f & center, float rad) {
    a = Vec2f(center.x, center.y - 2 * rad);
    b = Vec2f(center.x + RT_THREE * rad, center.y + rad);
    c = Vec2f(center.x - RT_THREE * rad, center.y + rad);
}

Particle::Particle( Vec2f loc ) {
    mLoc = loc;
    mVel = Rand::randVec2f() * INITIAL_SPEED;
    
    mColor = randColor();
    mRadius = Rand::randFloat(RAD_MAX);
    
    float decider = Rand::randFloat();
    
    if (decider < 0.33) {
        isTriangle = true;
    } else if (decider < 0.66) {
        isSquare = true;
    }
    
    age = 0;
    lifetime = Rand::randInt(50, 250);
    isDead = false;
}

void Particle::update( const Channel32f & channel, const ci::Vec2i & mouseLoc ) {
    if (++age > lifetime) isDead = true;

    mVel *= DECAY;
    mLoc += mVel;
}

void Particle::draw() {
    gl::color(mColor);
    
    if (isTriangle) {
        Triangle bounds(mLoc, mRadius);
        gl::drawSolidTriangle(bounds.a, bounds.b, bounds.c);
    } else if (isSquare) {
        Rectf bounds(mLoc.x - mRadius, mLoc.y - mRadius, mLoc.x + mRadius, mLoc.y + mRadius);
        gl::drawSolidRect(bounds);
    } else {
        gl::drawSolidCircle(mLoc, mRadius);
    }
}
