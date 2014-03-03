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

void ParticleController::update() {
    for (list<Particle>::iterator iter = mParticles.begin(); iter != mParticles.end(); ++iter) {
        iter->update();
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

void ParticleController::removeParticles(int amt) {
    for (int i = 0; i < amt; i++) {
        mParticles.pop_back();
    }
}