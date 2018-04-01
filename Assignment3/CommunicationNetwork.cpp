/*
Student Name: Ahmed AlHasani
Assignment: 3
Instructor: Samantha Molnar
I worked with Hassan
*/
#include "CommunicationNetwork.h"
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

CommunicationNetwork::CommunicationNetwork()
{
    head = NULL;
    tail = NULL;
}

CommunicationNetwork::~CommunicationNetwork()
{
    //dtor
}

void CommunicationNetwork::buildNetwork()
{
    City *temporary = new City("Los Angeles", NULL,""); //Start with the first city
    head = temporary; //Set head to the first city
    temporary -> next = new City("Phoenix", NULL, ""); //temporary pointer will
    temporary = temporary -> next; //Q
    temporary -> next= new City("Denver", NULL, "");
    temporary = temporary -> next;
    temporary -> next= new City("Dallas", NULL, "");
    temporary = temporary -> next;
    temporary -> next = new City("St. Louis",NULL,"");
    temporary = temporary -> next;
    temporary -> next = new City("Chicago",NULL,"");
    temporary = temporary -> next;
    temporary -> next = new City("Atlanta",NULL,"");
    temporary = temporary -> next;
    temporary -> next = new City("Washington, D.C.",NULL,"");
    temporary = temporary -> next;
    temporary -> next = new City("New York",NULL,"");
    temporary = temporary -> next;
    temporary -> next = new City("Boston",NULL,"");
}

void CommunicationNetwork::printNetwork()
{
    cout << "===CURRENT PATH==="<< endl;
    City *current = head -> next;  //this will point to the "next" node
    string message= head -> cityName;
    while (current != NULL)
    {
        cout<<message<<" -> ";
        message = current->cityName; // the "new" city's name will be stored in this variable
        current = current->next; //to iterate
    }
    if (current == NULL)
    {
        cout<<message<<" -> ";
    }
    cout<<"NULL"<<endl;
    cout<<"=================="<<endl;
}

void CommunicationNetwork::transmitMsg(char* myFile)
{
    ifstream myFile1;
    myFile1.open(myFile);
    if (myFile1.good())
    {
        string wordRead;
        City *current;
        if (head == NULL)
        {
            cout<<"Empty list"<<endl;
        }
        else
        {
            while (!myFile1.eof())
            {
                myFile1>>wordRead;
                current = head;
                current->message = wordRead;

                while (current != NULL)
                {
                    cout<<current->cityName<<" received "<<current->message<<endl;
                    if (current->next != NULL)
                    {
                        current->next->message = current->message;
                        current->message.clear();
                    }
                    current = current->next;
                }
            }
        }
    }
    else
        cout<<"File Did Not Open"<<endl;
}
void CommunicationNetwork::addCity(string city2,string city1)
{
    City *current = head;
    City *temporary;
    //cout<<current->cityName<<endl;
    while (current->cityName != city2 && current!=NULL)
    {
        current = current->next; //to iterate
    }
    if (current->cityName == city2)
    {
        temporary = new City(city1,current->next,""); // "current->next" points to the node after the previous city
        current->next = temporary; //connects the previous city to the new city we just added
    }
}
