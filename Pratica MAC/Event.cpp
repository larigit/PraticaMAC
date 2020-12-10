//
//  Event.cpp
//  PraticaMAC
//
//  Created by Raul C. Almeida Jr. on 18/10/17.
//  Copyright © 2017 UFPE - EON. All rights reserved.
//

#include "Event.hpp"

////////////////////////////////////////////////////////////////////////////////
Event::Event(TIME t, Packet* pkt)
:time(t), pktPtr (pkt){
}

////////////////////////////////////////////////////////////////////////////////
TIME Event::getTime(){
    return time;
}

// -------------------------------------------------------------------------- //
Packet* Event::rmvPacket(){
    Packet *auxPkt = pktPtr;
    pktPtr = NULL;
    return auxPkt;
}
