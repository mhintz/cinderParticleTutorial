//
//  ParticleController.cpp
//  TestCinderProject
//
//  Created by Mark Hintz on 2/3/14.
//
//

#include "cinder/Rand.h"

#include "ParticleController.h"

using namespace ci;
using namespace std;

ParticleController::ParticleController() {
}

ParticleController::ParticleController( int res ) {
    mRes = res;
    mXRes = app::getWindowWidth() / res;
    mYRes = app::getWindowHeight() / res;
    
    for ( int y = 0; y < mYRes; y++) {
        for (int x = 0; x < mXRes; x++) {
            addParticle( x, y );
        }
    }
}

void ParticleController::update() {
    for (list<Particle>::iterator iter = mParticles.begin(); iter != mParticles.end(); ++iter) {
        iter->update();
    }
}

void ParticleController::update( const Channel32f & channel ) {
    for (list<Particle>::iterator iter = mParticles.begin(); iter != mParticles.end(); ++iter) {
        iter->update( channel );
    }
}

void ParticleController::draw() {
    for (list<Particle>::iterator iter = mParticles.begin(); iter != mParticles.end(); ++iter) {
        iter->draw();
    }
}

void ParticleController::addParticles( int amt ) {
    for (int i = 0; i < amt; i++) {
        float x = Rand::randFloat( app::getWindowWidth() );
        float y = Rand::randFloat( app::getWindowHeight() );
        
        mParticles.push_back( Particle( Vec2f(x, y) ) );
    }
}

void ParticleController::addParticle( int xi, int yi ) {
    float x = (xi + 0.5f) * mRes;
    float y = (yi + 0.5f) * mRes;
    
    mParticles.push_back( Particle( Vec2f( x, y ) ) );
}

void ParticleController::removeParticles(int amt) {
    for (int i = 0; i < amt; i++) {
        mParticles.pop_back();
    }
}