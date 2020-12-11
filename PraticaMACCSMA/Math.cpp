//
//  Math.cpp
//  PraticaMAC
//
//  Created by Raul C. Almeida Jr. on 18/10/17.
//  Copyright © 2017 UFPE - EON. All rights reserved.
//

#include "Math.hpp"

////////////////////////////////////////////////////////////////////////////////
float Math::Exponential(float L){
    return (float) -log(1-Math::Uniform(0.0,1.0))/L;
}

// -------------------------------------------------------------------------- //
float Math::Uniform(float xmin,float xmax){
    float va;
    do {
        va = (float) rand()/(RAND_MAX);
        va += ((float) rand()/(RAND_MAX))/(RAND_MAX);
        va += (((float) rand()/(RAND_MAX))/(RAND_MAX))/(RAND_MAX);
    }
    while( (va<=0) || (va>=1.0-powl(RAND_MAX,-3)) );
    return xmin + va*(xmax - xmin);
}

