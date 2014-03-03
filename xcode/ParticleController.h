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
    void update();
    void draw();
    void addParticles( int amt );
    void removeParticles( int amt );
    std::list<Particle> mParticles;
};

#endif /* defined(__TestCinderProject__ParticleController__) */
