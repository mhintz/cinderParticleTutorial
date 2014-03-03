//
//  Util.c
//  TestCinderProject
//
//  Created by Mark Hintz on 2/3/14.
//
//

#include "Util.h"

float randOne() {
    return (float) (random() % 100) / 100.0f;
}

Color randColor() {
    return Color( randOne(), randOne(), randOne() );
}