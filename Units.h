/* 
 * File:   Units.h
 * Author: VictorPonten
 *
 * Created on October 7, 2017, 1:14 PM
 */

#ifndef UNITS_H
#define UNITS_H
#include <string>

#include "StatusEnum.h"
using namespace std;

class Units {
public:   
    
    
    Units(string, string);
    
    string getId();
    int getStatus();
    string getInfo();
    void setStatus(int);
      
private:
    string id;
    string info;
    int sensorValue;
    string sensorValueName;
    StatusEnum::Status status;
};

#endif /* UNITS_H */

