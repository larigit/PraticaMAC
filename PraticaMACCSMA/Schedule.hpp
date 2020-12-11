//
//  Schedule.hpp
//  PraticaMAC
//
//  Created by Raul C. Almeida Jr. on 18/10/17.
//  Copyright © 2017 UFPE - EON. All rights reserved.
//

#ifndef Schedule_hpp
#define Schedule_hpp

#include <stdio.h>
#include "assert.h"  //A função assert() testa se uma expressão é true (verdadeira).



#include "Definitions.hpp"
#include "Event.hpp"

////////////////////////////////////////////////////////////////////////////////
class Schedule{
public:
    Schedule();
    void initialize(TIME);
    void finalize();
    TIME getCurrentTime();
    void addEvent(Event*);
    Event* getCurrentEvent();
    TIME currentTime;
private:
    Event *firstEvent;
};

#endif /* Schedule_hpp */
