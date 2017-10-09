/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cloud.h
 * Author: VictorPonten
 *
 * Created on October 7, 2017, 1:13 PM
 */

#ifndef CLOUD_H
#define CLOUD_H
#include <vector>
#include "Units.h"
#include <string>
using namespace std;

class Cloud {
public:
    //försök göra private
    vector<Units> unitVector;
    Cloud();
    void pressY();
    void printMenu();
    int getInputValue();
    void printActiveUnits();
    void addUnit(string, int, string);
    void removeUnit(string);
    void initCloud();
    vector<Units> getUnitVector();
    void setStatus();
private:
    
};

#endif /* CLOUD_H */

