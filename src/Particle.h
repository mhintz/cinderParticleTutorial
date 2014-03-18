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
    ci::Vec2f mLocPer;
    ci::Vec2f newLoc;
    ci::Vec2f mDir;
    ci::Vec2f mDirToCursor;
    ci::Vec2f mVel;
    
    ci::Color mColor;
    
    float mRadius;
    float mScale;
    
    bool isTriangle;
    bool isSquare;
    
    int age;
    int lifetime;
    bool isDead;
    
    Particle();
    Particle( ci::Vec2f );
    void update();
    void update( const ci::Channel32f &, const ci::Vec2i & );
    void draw();
};

#endif /* defined(__TestCinderProject__Particle__) */
