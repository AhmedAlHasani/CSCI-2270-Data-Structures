/*
Name: Ahmed AlHasani
HW5
Instructor :Samantha Molnar
I helped a lot of students, so please be aware of this.
I spoke with Sam about this, and I asked each student to include my name if they used my code
*/
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <sstream>
#include <vector>
#include <string>
#include "Graph.h"
using namespace std;

void displayMenu();

int main(int argc, char* argv[])
{
    Graph myGraph;
    ifstream textFile;
    string city;
    string firstCity;
    string city1;
    string city2;
    string fileLine;
    int edge;
    bool firstLine = true;
    string arrayCities[20];


    textFile.open("zombieCities.txt");

    if (textFile.good())
    {
        while(getline(textFile, fileLine))
        {
            int index = 0; //for the array
            stringstream ssData(fileLine);
            while(getline(ssData,city,','))
            {
                if (firstLine == true && city != "cities")
                {
                    myGraph.addVertex(city);
                    arrayCities[index] = city;
                }
                else if (firstLine != true and index == 0)
                {
                    firstCity = city;
                }
                else if (firstLine != true)
                {
                    edge = atoi(city.c_str());
                    if (edge != -1)
                    {
                        myGraph.addEdge(firstCity, arrayCities[index], edge);
                    }
                }
                index++;
            }
            firstLine = false;
        }
    }
    else
    {
        cout<<"did not open file"<<endl;
    }

    bool quit = false;
    int input;

    // loop until the user quits
    while (quit != true)
    {
        displayMenu();
        cin >> input; // You can also use getline function to do this

        // used for user input
        string city1;
        string city2;

        //clear out cin
        cin.clear();
        cin.ignore(10000,'\n');

        switch (input)
        {
            case 1:
                myGraph.displayEdges();
                break;
            case 2:
                myGraph.assignDistricts();
                break;
            case 3:
                cout<<"Enter a starting city:"<<endl;
                getline(cin,city1);
                cout<<"Enter an ending city:"<<endl;
                getline(cin,city2);
                myGraph.shortestPath(city1, city2);
                break;
            case 4:
                cout << "Goodbye!" << endl;
                quit = true;
                break;

            default:
                cout << "Invalid Input" << endl;
                cin.clear();
                cin.ignore(10000,'\n');
                break;
        }
    }
}
void displayMenu()
{
    cout << "======Main Menu======" << endl;
    cout << "1. Print vertices" << endl;
    cout << "2. Find districts" << endl;
    cout << "3. Find shortest path" << endl;
    cout << "4. Quit" << endl;
    return;
}

