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
using std::cout;
using std::cin;



Cloud::Cloud() 
{
    vector<Units> unitVector;    
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
void Cloud::addUnit(string id1, string info1)
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
                string tempId = tempUnit.getId();
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
        pressY();
    }
    
    Units unit1(id1,info1);
    unitVector.push_back(unit1);    
}

void Cloud::initCloud()
{
    addUnit("Sensor 1","Temp.sensor");
    addUnit("Kylare 9","Kylare i serverhall");
    addUnit("Tryck 300","Trycksensor");
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
    cout << endl;
    cout << " ID "<<endl;
    cout << "------"<<endl;
    
    for (int i=0;i<unitVector.size();i++)
    {
        Units tempUnit = unitVector[i];
        string tempId = tempUnit.getId();
        int tempStatus = tempUnit.getStatus();
        if (tempStatus==1)
        {
            cout << tempId <<endl;
        }
    }
    
    cout << endl;
    pressY();
}

void Cloud::printAllUnits()
{
    cout << endl;
    cout << " ID "<<endl;
    cout << "------"<<endl;
    
    for (int i=0;i<unitVector.size();i++)
    {
        Units tempUnit = unitVector[i];
        string tempId = tempUnit.getId();
        int tempStatus = tempUnit.getStatus();
        cout << tempId <<endl;        
    }
    
    cout << endl;
}

void Cloud::removeUnit(string unitToRemove)
{
    if (unitVector.size()==0)
    {
        cout << "Det finns inga enheter att ta bort";
    }
    else
    {    
        int removedUnit;
        string yesOrNo;
        if (unitToRemove=="user input")
        {
            cout << "vill du se loggade enheter(y/n):";
            cin >> yesOrNo;
            if (yesOrNo=="y")
            {
                printAllUnits();
            }
            cout << "Id på vilken som ska tas bort: ";
            cin.clear();
            cin.ignore();
            getline(cin, unitToRemove);
            cout << endl;
        }
        for (int i=0;i<unitVector.size();i++)
        {
            Units tempUnit = unitVector[i];
            string tempString = tempUnit.getId();
            if (tempString == unitToRemove)
            {
                cout << "Tar bort: " + tempString << endl;
                removedUnit=i;
                        unitVector.erase(unitVector.begin()+removedUnit);
            }
        }

        cout << "Enheter kvar:" <<endl;
    }
    
    printAllUnits();
    pressY();
}

vector<Units> Cloud::getUnitVector()
{
    vector<Units> tempUnits = unitVector;
    return tempUnits;
}

void Cloud::setStatus(int index, int newStatus)
{
    unitVector[index].setStatus(newStatus);
}





