/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Dashboard.h
 * Author: VictorPonten
 *
 * Created on October 7, 2017, 1:14 PM
 */

#ifndef DASHBOARD_H
#define DASHBOARD_H
#include <vector>
#include "Units.h"
#include "Cloud.h"


class Dashboard {
public:
    vector<Units> unitVector;
    Cloud* cloud1;
    Dashboard(Cloud* cloud);
    void getDashboard();
    int printDetails(string);
    void setStatus(int,int);

private:
};

#endif /* DASHBOARD_H */

