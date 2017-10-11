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

class Cloud {
public:
    Cloud();
    void pressY();
    void printMenu();
    int getInputValue();
    void printActiveUnits();
    void printAllUnits();
    void addUnit(string, string);
    void removeUnit(string);
    void initCloud();
    vector<Units> getUnitVector();
    void setStatus(int,int);
private:
    vector<Units> unitVector;
};

#endif /* CLOUD_H */

