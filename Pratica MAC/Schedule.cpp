//
//  Schedule.cpp
//  PraticaMAC
//
//  Created by Raul C. Almeida Jr. on 18/10/17.
//  Copyright © 2017 UFPE - EON. All rights reserved.
//

#include "Schedule.hpp"

////////////////////////////////////////////////////////////////////////////////
Schedule::Schedule(){
    firstEvent = NULL;
}

////////////////////////////////////////////////////////////////////////////////
void Schedule::initialize(TIME t){
    currentTime = t;
    assert(firstEvent == NULL);
}

// -------------------------------------------------------------------------- //
void Schedule::finalize(){
    Event *auxEvent;
    while(firstEvent != NULL){
        auxEvent = firstEvent;
        firstEvent = firstEvent->nextEvent;
        delete auxEvent->rmvPacket();
        delete auxEvent;
    }
}

// -------------------------------------------------------------------------- //
TIME Schedule::getCurrentTime(){
    return currentTime;
}

// -------------------------------------------------------------------------- //
void Schedule::addEvent(Event* evt){
    if(firstEvent == NULL){
        firstEvent = evt;
        evt->nextEvent = NULL;
    }
    else{
        if(evt->getTime() < firstEvent->getTime()){   //fez uma troca
            evt->nextEvent = firstEvent;
            firstEvent = evt;
        }
        else{
            Event *auxEvent = firstEvent;
            while(auxEvent != NULL){
                if(auxEvent->nextEvent != NULL && auxEvent->nextEvent->getTime() < evt->getTime())
                    auxEvent = auxEvent->nextEvent;
                else{
                    evt->nextEvent = auxEvent->nextEvent;
                    auxEvent->nextEvent = evt;
                    break;
                }
            }
        }
    }
}


// -------------------------------------------------------------------------- //
Event* Schedule::getCurrentEvent(){
    currentTime = firstEvent->getTime();
    Event *auxEvent = firstEvent;
    firstEvent = firstEvent->nextEvent;
    return auxEvent;
}
