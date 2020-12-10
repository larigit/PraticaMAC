//
//  Packet.hpp
//  PraticaMAC
//
//  Created by Raul C. Almeida Jr. on 18/10/17.
//  Copyright © 2017 UFPE - EON. All rights reserved.
//

#ifndef Packet_hpp
#define Packet_hpp

#include <stdio.h>
#include "Definitions.hpp"

////////////////////////////////////////////////////////////////////
class Packet{
public:
    Packet(TIME, TIME);  //construtor
    //
    TIME getStartTime(); //acessor
    TIME getEndTime();
    TIME getDuration();
    //
    static void removePastPackets(); //atributo
private:
    TIME startTime;
    TIME endTime;    
};

#endif /* Packet_hpp */
