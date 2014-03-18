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

ParticleController::ParticleController() {}

void ParticleController::update( const Channel32f & channel, const Vec2i & mouseLoc ) {
    for (list<Particle>::iterator prtcl = mParticles.begin(); prtcl != mParticles.end(); ) {
        if (prtcl->isDead) {
            prtcl = mParticles.erase(prtcl);
        } else {
            prtcl->update( channel, mouseLoc );
            ++prtcl;
        }
    }
}

void ParticleController::draw() {
    for (list<Particle>::iterator prtcl = mParticles.begin(); prtcl != mParticles.end(); ++prtcl) {
        prtcl->draw();
    }
}

void ParticleController::addParticles( int amt, const Vec2i & mouseLoc, const Vec2f & mouseVel  ) {
    for (int i = 0; i < amt; i++) {
        Vec2f randVec = Rand::randVec2f() * 10.0f;
        
        mParticles.push_back( Particle( mouseLoc + randVec ) );
    }
}

void ParticleController::removeParticles(int amt) {
    for (int i = 0; i < amt; i++) {
        mParticles.pop_back();
    }
}