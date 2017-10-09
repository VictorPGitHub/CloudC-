/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: VictorPonten
 *
 * Created on October 7, 2017, 1:12 PM
 */

#include <cstdlib>
#include "Dashboard.h"
#include "Cloud.h"

using namespace std;

/*
 * 
 */
int main() 
{
    int inputValue = 0;
    Cloud cloud;
    Cloud* cloudPtr = &cloud;
    Dashboard dash(cloudPtr);
    cloud.initCloud();
    
    while(inputValue != 5)
    {
        cloud.printMenu();
        inputValue=0;
        
        while (inputValue==0)
        {
            inputValue=cloud.getInputValue();
    
        } 
        
        if(inputValue==1)
        {           
            cloud.printActiveUnits();
            inputValue=0;
        }
        
        if (inputValue==2)
        {
            cloud.addUnit("user input",0,"");
            inputValue=0;
        }
        
        if (inputValue==3)
        {
            cloud.removeUnit("user input");
            inputValue=0;
        }
        
        if (inputValue==4)
        {
            dash.getDashboard();     
            inputValue=0;
        }
    }
    
    return 0;
}

