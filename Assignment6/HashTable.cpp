/*
Student Name: Ahmed AlHasani
CSCI 2270
Samantha Molnar
*/
#include "HashTable.h"
#include <iostream>

using namespace std;

HashTable::HashTable()
{
    for (int i = 0; i<tableSize; i++)
    {
        hashTable[i] = NULL;
    }
}

HashTable::~HashTable()
{}

int HashTable::hashSum(string x, int s)
{
    int sum = 0;
    for (int i = 0; i < x.size(); i++)
    {
        sum = sum + x[i];
    }
    return sum % s;
}

void HashTable::insertMovie(string name, int year)
{
    int index = hashSum(name,tableSize);
    HashElem* newMovie = new HashElem(name,year); //will hold the NEW movie with the same index

    if (hashTable[index] == NULL)
        hashTable[index]= newMovie;
    else
    {
        HashElem* temp = hashTable[index]; //will hold the FIRST movie with the same index
        while (temp->next!=NULL)
        {
            temp = temp->next;
        }
        newMovie->previous = temp;
        temp->next = newMovie;
    }
}

void HashTable::findMovie(string name)
{
    int index = hashSum(name,tableSize);
    bool found = false;
    HashElem* temp = NULL;
    if (hashTable[index] != NULL)
    {
        temp = hashTable[index];
        while(temp!=NULL)
        {
            if(temp->title == name)
            {
                found = true;
                break;
            }
            else
                temp = temp->next;
        }
    }
    if (found == true)
        cout<<index<<":"<<temp->title<<":"<<temp->year<<endl;
    else
        cout<<"not found"<<endl;
}

void HashTable::deleteMovie(std::string name)
{
    int index = hashSum(name,tableSize);
    HashElem* temp = NULL;
    bool found = false;

    if (hashTable[index] != NULL)
    {
        temp = hashTable[index];
        while(temp!=NULL)
        {
            if(temp->title == name)
            {
                found = true;
                break;
            }
            else
                temp = temp->next;
        }
    }
    if (found == true && temp == hashTable[index])
    {
        if (hashTable[index]->next != NULL)
        {
            temp = hashTable[index];
            hashTable[index] = hashTable[index]->next;
            hashTable[index]->previous = NULL;
            delete temp;
        }
        else if (hashTable[index]->next == NULL)
        {
            hashTable[index] = NULL;
        }
    }
    else if (found == true && temp != hashTable[index])
    {
        if (temp->previous!=NULL)
            temp->previous->next = temp->next;
        else
            temp->previous = NULL;
        if (temp->next!=NULL)
            temp->next->previous = temp->previous;
        else
            temp->next = NULL;
        delete temp;
    }
    else
        cout<<"not found"<<endl;
}

void HashTable::printTableContents()
{
    HashElem* temp = NULL;
    bool notEmpty = true;
    for(int i = 0; i<tableSize; i++)
    {
        if(hashTable[i]!=NULL)
        {
            notEmpty  = false;
            cout<<hashTable[i]->title<<":"<<hashTable[i]->year<<endl;
            if (hashTable[i]->next != NULL)
            {
                temp = hashTable[i]->next;
                while (temp!=NULL)
                {
                    cout<<temp->title<<":"<<temp->year<<endl;
                    temp = temp->next;
                }
            }
        }
    }
    if (notEmpty == true)
        cout<<"empty"<<endl;
}
