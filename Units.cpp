/* 
 * File:   Units.cpp
 * Author: VictorPonten
 * 
 * Created on October 7, 2017, 1:14 PM
 */

#include "Units.h"
#include <string>
#include <iostream>
using std::cout;
using std::cin;


string id;
int status;
string info;

Units::Units(string id1,int status1,string info1) 
{
    id=id1;
    status=status1;
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
    return status;
}
string Units::getInfo()
{
    return info;
}

//set functions
void Units::setStatus(int status1)
{
    status=status1;
}






