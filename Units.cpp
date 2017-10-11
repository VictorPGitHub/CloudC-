/* 
 * File:   Units.cpp
 * Author: VictorPonten
 * 
 * Created on October 7, 2017, 1:14 PM
 */

#include "Units.h"
#include "StatusEnum.h"
#include <string>
#include <iostream>
using std::cout;
using std::cin;




Units::Units(string id1, string info1) 
{
    id=id1;
    status = StatusEnum::On;
    info=info1; 
    
    // should be defined in inheritance subclasses of Units 
    //int sensorValue;
    //const string sensorValueName;
}
// all get functions
string Units::getId()
{
    return id;
}
    
int Units::getStatus()
{
    int statusReturn = status;
    return statusReturn;
}
string Units::getInfo()
{
    return info;
}

//set functions
void Units::setStatus(int status1)
{
    if (status1==0)
    {
        status=StatusEnum::Off;
    }
        if (status1==1)
    {
        status=StatusEnum::On;
    }
}






