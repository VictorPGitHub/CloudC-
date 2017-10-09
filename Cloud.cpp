/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cloud.cpp
 * Author: VictorPonten
 * 
 * Created on October 7, 2017, 1:13 PM
 */

#include "Cloud.h"
#include "Units.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<Units> unitVector;

Cloud::Cloud() 
{
    
}

void Cloud::pressY()
{
    string tempString = "";
    cout << "tryck y för att fortsätta: ";
    while (tempString != "y")
    {
        cin >> tempString;
    
    }
    cout << endl;
}
void Cloud::addUnit(string id1, int status1, string info1)
{
    if (id1=="user input")
    {
        int checkIfIdExist = 0;
        cout << "Enter ID:";
        cin.clear();
        cin.ignore();
        getline(cin, id1);


        while (checkIfIdExist==0) 
        {
            checkIfIdExist=1;
        
            for (int i=0;i<unitVector.size();i++)
            {
                Units tempUnit = unitVector[i];
                string tempId = tempUnit.id;
                if (tempId==id1)
                {                    
                    checkIfIdExist=0;
                }
            
            }
            if (checkIfIdExist==0)
                {
                    cout << "ID finns redan ange nytt:";
                    cin.clear();
                    cin.ignore();
                    cin >>id1;                    
                }
        }

        cout <<endl << "Enter Info:";
        getline(cin, info1);
        status1=1;
        pressY();
    }
    
    Units unit1(id1,status1,info1);
     unitVector.push_back(unit1);    
}

void Cloud::init_cloud()
{
    addUnit("Sensor 1",1,"Temp.sensor");
    addUnit("Kylare 9",1,"Kylare i serverhall");
    addUnit("Tryck 300",1,"Trycksensor");
}

void Cloud::printMenu()
{
    cout << "Huvudmeny"<<endl;
 cout << "1) Visa anslutna enheter" << endl;
cout << "2) Lägg till en ny enhet." << endl;
cout << "3) Ta bort enheter" << endl;
cout << "4) Visa instrumentpanelen (för att se status och ändra enheter)"<<endl;
cout << "5) Avsluta"<<endl;

}

int Cloud::getInputValue()
{
    int inputValue;
    cin >> inputValue;
    return inputValue;
}

void Cloud::printActiveUnits()
{
    
    cout << " ID "<<endl;
    cout << "------"<<endl;
    
    for (int i=0;i<unitVector.size();i++)
    {
        Units tempUnit = unitVector[i];
        string tempId = tempUnit.id;
        int tempStatus = tempUnit.status;
        if (tempStatus==1)
        {
            cout << tempId <<endl;
        }
    }
    pressY();
}

void Cloud::removeUnit(string unitToRemove)
{
    int removedUnit;
    string yesOrNo;
    if (unitToRemove=="user input")
    {
        cout << "vill du se aktiva enheter(y/n):";
        cin >> yesOrNo;
        if (yesOrNo=="y")
        {
            printActiveUnits();
        }
        cout << "Id på vilken som ska tas bort: ";
        cin >> unitToRemove;
        cout << endl;
    }
    for (int i=0;i<unitVector.size();i++)
    {
        Units tempUnit = unitVector[i];
        string tempString = tempUnit.get_id();
        if (tempString == unitToRemove)
        {
            cout << "tar bort " + tempString << endl;
            removedUnit=i;
                    unitVector.erase(unitVector.begin()+removedUnit);
        }


    }
    cout << "enheter kvar" <<endl;
    

    printActiveUnits();

    
}

vector<Units> Cloud::getUnitVector()
{
    vector<Units> tempUnits = unitVector;
    return tempUnits;
}





