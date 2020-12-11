//
//  Math.hpp
//  PraticaMAC
//
//  Created by Raul C. Almeida Jr. on 18/10/17.
//  Copyright © 2017 UFPE - EON. All rights reserved.
//

#ifndef Math_hpp
#define Math_hpp

#include <stdio.h>
#include <math.h>
#include <stdlib.h>



////////////////////////////////////////////////////////////////////////////////
class Math{
public:
    static float Exponential(float L);
    static float Uniform(float xmin,float xmax);
    template <class T>
    static const T& MAX (const T& a, const T& b);
private:
};

// -------------------------------------------------------------------------- //
template <class T>
const T& Math::MAX (const T& a, const T& b){
    return (a>b)?a:b;
}

#endif /* Math_hpp */
