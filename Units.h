/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

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
    string id;
    int status;
    string info;
    
    Units(string, int, string);
    string get_id();
    int get_status();
    string get_info();
      
private:

};



#endif /* UNITS_H */

