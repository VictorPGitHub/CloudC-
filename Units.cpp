/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Units.cpp
 * Author: VictorPonten
 * 
 * Created on October 7, 2017, 1:14 PM
 */

#include "Units.h"
#include <string>
#include <iostream>

using namespace std;

string id;
int status;
string info;
int sensorValue;
string sensorValueName;

Units::Units(string id1,int status1,string info1) 
{
    id=id1;
    status=status1;
    info=info1;
            
}

string Units::get_id()
{
    return id;
}
    
int Units::get_status()
{
    return status;
}
string Units::get_info()
{
    return info;
}
    





