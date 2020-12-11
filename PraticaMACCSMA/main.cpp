//
//  main.cpp
//  PraticaMAC
//
//  Created by Raul C. Almeida Jr. on 18/10/17.
//  Copyright © 2017 UFPE - EON. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <fstream>
#include <limits>
#include <climits>
#include <vector>
using namespace std;

#include "Definitions.hpp"
#include "Packet.hpp"
#include "Event.hpp"
#include "Schedule.hpp"
#include "Math.hpp"



////////////////////////////////////////////////////////////////////////////////
void PacketArrival(Schedule&, TIME, TIME);
//void setEvent(Event*, Packet*, TIME);
//void Schedule(Event*);


ofstream Results("Results.txt");


////////////////////////////////////////////////////////////////////////////////
int main(){
    cout<<"Start of Simulation"<<endl;
    Schedule schedule;
    Packet *pkt, *lastSuccPkt;
    TIME ChOccEndTime, AvrPktDuration = 1.0;
    float la, LaMin = 0.1, LaMax = 3.0, LaPasso = 0.1;
    float numPkt, numPktMax = 10000, numPktBloq, thrp;
    for(la = LaMin; la <= LaMax; la += LaPasso) {  // la é a taxa de chegada de requisicoes //30 loops
        schedule.initialize(0.0);
        ChOccEndTime = schedule.getCurrentTime();
        numPkt = 0.0;
        numPktBloq = 0.0;
        thrp = 0.0;
        lastSuccPkt = NULL;
        PacketArrival(schedule, schedule.getCurrentTime(), AvrPktDuration);//Creates the first packet that arrives to the network;
        //Start the simulation:
        while(numPkt < numPktMax){
            Event *curEvent = schedule.getCurrentEvent();
            pkt = curEvent->rmvPacket();   //retorna a packet que foi removido

            /////////////////
            while(ChOccEndTime > schedule.getCurrentTime()){   //enquanto canal estiver ocupado, não transmite nada
                schedule.currentTime +=Math::Exponential(la);   //gera time aleatorio
            }                                                    //se canal estiver livre, executa o resto do codigo
    
            if(lastSuccPkt != NULL){ //lastSuccPkt was successfully transmitted (i.e., did not receive interference)
                thrp += lastSuccPkt->getDuration();            
                delete lastSuccPkt;
            }
            lastSuccPkt = pkt; //pkt starts a successfull transmission
            ChOccEndTime = pkt->getEndTime();
            //////////////////////////
        
        PacketArrival(schedule, schedule.getCurrentTime()+Math::Exponential(la), AvrPktDuration); //Schedule the arrival of a new packet
        numPkt++;
        delete curEvent;
        }
        cout<<"Load= "<<la*AvrPktDuration<<"\t Throughput= "<<(float) thrp/ChOccEndTime<<"\t PB= "<<(float) numPktBloq/numPktMax<<endl;
        Results<<la*AvrPktDuration<<" \t"<<(float) thrp/ChOccEndTime<<endl;
        schedule.finalize();
    }
    cout<<"End of Simulation:"<<endl;
    cin.get();
    return 0;
}

////////////////////////////////////////////////////////////////////////////////
void PacketArrival(Schedule& schedule, TIME arrivalTime, TIME AvrPktDuration){
    Packet* auxPkt = new Packet(arrivalTime, arrivalTime + Math::Exponential(1.0/AvrPktDuration));
    Event *auxEvt = new Event(arrivalTime, auxPkt); //Create a new Event with the packet
    schedule.addEvent(auxEvt); //add Event to Schedule
}

