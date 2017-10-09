/* 
 * File:   Dashboard.cpp
 * Author: VictorPonten
 * 
 * Created on October 7, 2017, 1:14 PM
 */

#include "Dashboard.h"
#include <vector>
#include "Units.h"
#include <iostream>
#include "Cloud.h"
using std::cout;
using std::cin;

Cloud* cloud1;

//constructs dashboard with corresponding cloud
Dashboard::Dashboard(Cloud* cloud) 
{
    cloud1 = cloud; 
    vector<Units> unitVector;
}

//creates the dashboard and sends it to main
void Dashboard::getDashboard()
{     
    unitVector = cloud1->getUnitVector();
    string blankSpace = "                         ";
    int maxIdNameLength =10;
    int maxInfoNameLength =25;
    
    cout << "-----------------------------------------------"<<endl;
    cout << "|         Kontrollpanel                       |"<<endl;
    cout << "-----------------------------------------------"<<endl;
    cout << "|    ID    | Status |    Info                 |"<<endl;
    cout << "-----------------------------------------------"<<endl;
    
    for (int i=0;i<unitVector.size();i++)
    {
        Units tempUnit = unitVector[i];
        string tempId = tempUnit.getId();
        int tempStatus = tempUnit.getStatus();
        string tempInfo = tempUnit.getInfo();
        
        int blankSpaceNr = maxIdNameLength - tempId.size();
        
        cout << "|"+tempId + blankSpace.substr(0,blankSpaceNr)+ "|   ";
        cout << tempStatus << "    |";
        blankSpaceNr = maxInfoNameLength - tempInfo.size();
        cout << tempInfo + blankSpace.substr(0,blankSpaceNr)+"|"<<endl;
        cout << "-----------------------------------------------"<<endl;
    }
    
    //prints details or return to menu
    cout << "Ange Enhet att ändra eller meny:";
    string userInput;
    int inputFound;
    cin.clear();
    cin.ignore();
    getline(cin, userInput);
    if (userInput!="meny")
    {
        inputFound = printDetails(userInput);
        
        if(inputFound==1)
        {
            cout << endl;
            cout << "Enhet saknas" <<endl;
            cloud1->pressY();
        }
    }
    
    else
    {
        cout << endl;
    }
}

// the function printsDetails. more details needs to be added in Units to get
int Dashboard::printDetails(string unitId)
{
    vector<Units> unitVector = cloud1->getUnitVector();
    int unitFound = 1;
    int unitIndex=10000;
    
    for (int i=0;i<unitVector.size();i++)
    {
        Units tempUnit = unitVector[i];
        string tempId = tempUnit.getId();
        if (unitId==tempId)
        {
            unitIndex=i;
            unitFound=0;
        }
    }
    string userInput;
    int changeStatus;
    
    if (unitFound==0)
    {
        cout << "Visar information om " + unitVector[unitIndex].getId() << endl;
        
        if (unitVector[unitIndex].getStatus()==1)
        {
            cout << "1) Avaktivera" << endl;
            changeStatus=0;
        }
        
        if (unitVector[unitIndex].getStatus() ==0)
        {
            cout << "1) Aktivera" << endl;
            changeStatus=1;
        }
        cout << "2) tillbaka till menyn" << endl;
        cin >> userInput;
        
        if (userInput=="1")
        {
            setStatus(unitIndex,changeStatus);
            cout<<endl;
        }
    }          
    return unitFound;
}

// Sets status from the Dashboard menu
void Dashboard::setStatus(int index,int status)
{
    cloud1->setStatus(index,status);
}



