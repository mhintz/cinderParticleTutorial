//
//  Particle.h
//  TestCinderProject
//
//  Created by Mark Hintz on 2/3/14.
//
//

#ifndef __TestCinderProject__Particle__
#define __TestCinderProject__Particle__

class Particle {
public:
    ci::Vec2f mLoc;
    ci::Vec2f mDir;
    ci::Color mColor;
    float mVel;
    float mRadius;
    
    Particle();
    Particle( ci::Vec2f );
    void update();
    void update( const ci::Channel32f & );
    void draw();
};

#endif /* defined(__TestCinderProject__Particle__) */
