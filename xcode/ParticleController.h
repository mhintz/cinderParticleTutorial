//
//  ParticleController.h
//  TestCinderProject
//
//  Created by Mark Hintz on 2/3/14.
//
//

#ifndef __TestCinderProject__ParticleController__
#define __TestCinderProject__ParticleController__

#include <list>

#include "cinder/Channel.h"
#include "cinder/Perlin.h"

#include "Particle.h"

class ParticleController {
public:
    ParticleController();
    void update( const ci::Channel32f &, const ci::Vec2i & );
    void draw();
    void addParticles( int, const ci::Vec2i &, const ci::Vec2f & );
    void removeParticles( int );
    
    std::list<Particle> mParticles;
};

#endif /* defined(__TestCinderProject__ParticleController__) */
