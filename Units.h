/* 
 * File:   Units.h
 * Author: VictorPonten
 *
 * Created on October 7, 2017, 1:14 PM
 */

#ifndef UNITS_H
#define UNITS_H
#include <string>
using namespace std;

class Units {
public:   
    Units(string, int, string);
    
    string getId();
    int getStatus();
    string getInfo();
    void setStatus(int);
      
private:
    string id;
    int status;
    string info;
    int sensorValue;
    string sensorValueName;
};

#endif /* UNITS_H */

