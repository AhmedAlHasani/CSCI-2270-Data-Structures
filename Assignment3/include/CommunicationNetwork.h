/*
Student Name: Ahmed AlHasani
Assignment: 3
Instructor: Samantha Molnar
*/
#ifndef COMMUNICATIONNETWORK_H
#define COMMUNICATIONNETWORK_H
#include <iostream>
using namespace std;

struct City
{
    string cityName; //these 3 variables make a city node
    string message;
    City *next;

    City() {}; // default constructor

    City(string initName, City *initNext, string initMessage) // this is what we are passing
    {
        cityName = initName;
        next = initNext;
        message = initMessage;
    }

};

class CommunicationNetwork
{
public:
    CommunicationNetwork();
    ~CommunicationNetwork();
    void addCity(std::string, std::string);
    void buildNetwork();
    void transmitMsg(char *); //this is like a string
    void printNetwork();
protected:
private:
    City *head;
    City *tail;
};

#endif // COMMUNICATIONNETWORK_H
