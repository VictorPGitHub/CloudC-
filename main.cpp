/* 
 * File:   main.cpp
 * Author: VictorPonten
 *
 * Created on October 7, 2017, 1:12 PM
 */

#include <cstdlib>
#include "Dashboard.h"
#include "Cloud.h"

int main() 
{
    //int that handles the main loop
    int inputValue = 0;
    
    //get instance of cloud, fill it up with Units and gets pointer
    Cloud cloud;
    Cloud* cloudPtr = &cloud;    
    cloud.initCloud();
    
    //get instance of Dashboard and sends pointer of initiated cloud
    Dashboard dash(cloudPtr);
    
    //Start loop, could have been done with case instead and maybe moved to cloud
    //gets the cloud menu and exit on 5
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
            //did not get pre defined inputs to work so had to use (0,"")
            //could have been solved with case or likewise instead in add function
            cloud.addUnit("user input","");
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

