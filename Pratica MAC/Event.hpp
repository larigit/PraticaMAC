//
//  Event.hpp
//  PraticaMAC
//
//  Created by Raul C. Almeida Jr. on 18/10/17.
//  Copyright © 2017 UFPE - EON. All rights reserved.
//

#ifndef Event_hpp
#define Event_hpp

#include <stdio.h>
#include "Packet.hpp"

class Event {
public:
    Event(TIME, Packet*);
    TIME getTime();
    Packet* rmvPacket();
private:
    TIME time;    
    Packet* pktPtr;
public:
    Event *nextEvent;
};

#endif /* Event_hpp */