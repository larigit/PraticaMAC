//
//  Packet.cpp
//  PraticaMAC
//
//  Created by Raul C. Almeida Jr. on 18/10/17.
//  Copyright © 2017 UFPE - EON. All rights reserved.
//

#include "Packet.hpp"

////////////////////////////////////////////////////////////////////////////////
Packet::Packet(TIME st, TIME et)
:startTime(st), endTime(et){
}


////////////////////////////////////////////////////////////////////////////////
TIME Packet::getStartTime(){
    return startTime;
}

// -------------------------------------------------------------------------- //
TIME Packet::getEndTime(){
    return endTime;
}

// -------------------------------------------------------------------------- //
TIME Packet::getDuration(){
    return endTime - startTime;
}
