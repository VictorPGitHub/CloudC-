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
    Dashboard(Cloud* cloud);
    
    void getDashboard();
    int printDetails(string);
    void setStatus(int,int);

private:
    Cloud* cloud1;
    vector<Units> unitVector;
};

#endif /* DASHBOARD_H */

