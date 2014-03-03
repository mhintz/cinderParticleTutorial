//
//  ParticleController.h
//  TestCinderProject
//
//  Created by Mark Hintz on 2/3/14.
//
//

#ifndef __TestCinderProject__ParticleController__
#define __TestCinderProject__ParticleController__

#include "Particle.h"
#include <list>

class ParticleController {
public:
    ParticleController();
    ParticleController( int );
    void update();
    void update( const ci::Channel32f & );
    void draw();
    void addParticles( int );
    void addParticle( int, int );
    void removeParticles( int );
    
    std::list<Particle> mParticles;
    int mRes;
    int mXRes;
    int mYRes;
};

#endif /* defined(__TestCinderProject__ParticleController__) */
