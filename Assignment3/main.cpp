/*
Student Name: Ahmed AlHasani
Assignment: 3
Instructor: Samantha Molnar
I worked with Hassan
*/

#include <iostream>
#include "CommunicationNetwork.h"
#include <iostream>
#include <sstream>
using namespace std;
/*
void Menu(CommunicationNetwork networkBuild, char* argv[])
{
    int choice;
    string city1;
    string city2;

    cout<<"=====Main Menu====="<<endl;
    cout<<"1. Build Network"<<endl;
    cout<<"2. Print Network Path"<<endl;
    cout<<"3. Transmit Message Coast-To-Coast"<<endl;
    cout<<"4. Add City"<<endl;
    cout<<"5. Quit"<<endl;
    cout<<endl;
    //cout<<"Enter an Option: ";
    cin>>choice;

    if (choice == 1)
    {
        networkBuild.buildNetwork();
        Menu(networkBuild, argv);
    }
    else if (choice == 2)
    {
        networkBuild.printNetwork();
        Menu(networkBuild, argv);
    }
    else if (choice == 3)
    {
        networkBuild.transmitMsg("messageIn.txt");
        //networkBuild.transmitMsg(argv[1]);
        Menu(networkBuild, argv);
    }
    else if (choice == 4)
    {
        cout<<"Enter a city name:"<<endl;
        cin>>city1;
        cout<<"Enter a previous city name:"<<endl;
        cin>>city2;
        networkBuild.addCity(city1, city2);
        Menu(networkBuild, argv);
    }
    else if (choice == 5)
    {
        cout<<"Goodbye!"<<endl;
    }
    else
        Menu(networkBuild, argv);
}

int main(int argc, char* argv[])
{
    CommunicationNetwork networkBuild;
    Menu(networkBuild, argv);
}
*/

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "CommunicationNetwork.h"

using namespace std;

void displayMenu();

int main(int argc, char* argv[])
{
    // indicates the user is ready to leave the program
    bool quit = false;
    int input;
    CommunicationNetwork cn;

    // loop until the user quits
    while (quit != true)
    {
        displayMenu();
        cin >> input; // You can also use getline function to do this

        // used for user input
        string cityNew;
        string cityPrevious;
        string message;

        //clear out cin
        cin.clear();
        cin.ignore(10000,'\n');

        switch (input)
        {
            case 1:
                cn.buildNetwork();
                cn.printNetwork();
                break;
            case 2:
                cn.printNetwork();
                break;
            case 3:
                cn.transmitMsg("messageIn.txt");
                break;
            case 4:
                cout << "Enter a city name: " << endl;
                getline(cin,cityNew);
                cout << "Enter a previous city name: " << endl;
                getline(cin,cityPrevious);

                cn.addCity(cityPrevious, cityNew);
                break;

            case 5:
                cout << "Goodbye!" << endl;
                quit = true;
                break;
            case 6: //not graded in this assignment

                //head = deleteEntireNetwork(head);
                cout << "Deleted network" << endl;
                break;
            // quit
            // invalid input
            default:
                cout << "Invalid Input" << endl;
                cin.clear();
                cin.ignore(10000,'\n');
                break;
        }
    }

    return 0;

}

void displayMenu()
{
    cout << "======Main Menu======" << endl;
    cout << "1. Build Network" << endl;
    cout << "2. Print Network Path" << endl;
    cout << "3. Transmit Message Coast-To-Coast" << endl;
    cout << "4. Add City" << endl;
    cout << "5. Quit" << endl;
    return;
}
