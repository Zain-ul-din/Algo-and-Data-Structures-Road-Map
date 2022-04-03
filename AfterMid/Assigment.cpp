//
// Created by 97152 on 01/04/2022.
//

#include<iostream>
using namespace std;

int main () {

    /// Given Data

    const int labours = 150 , masons = 50 , carpenters = 20 ,
    painters = 10 , plumbers = 5 , electricians = 5 ,
    supervisor = 5 , guards = 5;

    // Per Day Worker Cost
    const int laboursWages = 500 , masonsWages = 700
    , carpentersWages = 800 , painterWages = 1000
    ,plumberWages = 1200 , electriciansWages = 1500
    ,supervisorWages = 2500 , guardsWages = 2000;

    const int labourOverTimeCost = 150 ,// 1.5 h cost
    masonOverTimeCost = 250 , // 2.5h cost
    electriciansOverTimeCost = 100; // 1h cost



     const int labourOverTime = 1 , masonOverTime = 1 ,
            electriciansOverTime = 2;

     const int totalDays = 30; // one month

     const unsigned int perDayCost = // per day cost
            (laboursWages * labours) + ((labourOverTime / 1.5) * masonOverTimeCost)
            (masonsWages * masons) + ((masonOverTime / 2.5) * masonOverTimeCost) +
            (carpentersWages * carpenters ) +
            (painterWages * painters) +
            (plumbers * plumberWages) +
            (electriciansWages * electricians) + (electriciansOverTime * electriciansOverTimeCost) +
            (supervisorWages * supervisor) +
            (guardsWages * guards);

     const unsigned int totalWorkerCost = perDayCost * totalDays;
     const unsigned int landCost = 15375000;

     std::cout << "Total Project Cost : " << landCost << "\n";
}

