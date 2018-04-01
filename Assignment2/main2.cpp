

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>

using namespace std;

struct wordsInFile
{

    string word;
    int wordCount;

};

bool CommonWord(string word)
{
    return ((word == "the") || (word == "be") || (word == "to")  || (word == "of") || (word == "and") || (word == "a") || (word == "in") || (word == "that") || (word == "have") || (word == "i") || (word == "it") || (word == "for") || (word == "not") || (word == "on") || (word == "with") || (word == "he") || (word == "as") || (word == "you") || (word == "do") || (word == "at") || (word == "this") || (word == "but") || (word == "his") || (word == "by") || (word == "from") || (word == "they") || (word == "we") || (word == "say") || (word == "her") || (word == "she") || (word == "or") || (word == "an") || (word == "will") || (word == "my") || (word == "one") || (word == "all") || (word == "would") || (word == "there") || (word == "their") || (word == "what") || (word == "so") || (word == "up") || (word == "out") || (word == "if") || (word == "about") || (word == "who") || (word == "get") || (word == "which") || (word == "go") || (word == "me") || (word == ""));
}


wordsInFile *arrayDoubling (wordsInFile* wArray, int arraySize)
{
    //arraySize = arraySize*2;
    wordsInFile* array2 = new wordsInFile[arraySize]; //arraySize is doubled in the main
    for (int index = 0; index<arraySize/2; index++)
    {
        array2[index]=wArray[index];
    }
    delete []wArray;
    return array2;
}

void *arraySorting (wordsInFile* wArray, int arraySize, int numTop)
{
    wordsInFile temp;

    for (int i = arraySize-1; i>0 ; i--)
    {
        for (int j = arraySize-1; j>0 ; j--)
        {
            if (wArray[j].wordCount > wArray[j-1].wordCount)
            {
                temp = wArray[j-1];
                wArray[j-1] = wArray[j];
                wArray[j] = temp;
            }
        }
    }
    for (int i = 0; i<numTop; i++)
    {
        cout<<wArray[i].wordCount<<" - "<<wArray[i].word<<endl;
    }
}

int main(int argc, char *argv[])
{
    ifstream myFile;
    string data;
    int numTop;
    int sum =0;

    myFile.open("HungerGames_edit.txt");
    numTop = 10;

    //myFile.open(argv[1]);
    //numTop = atoi(argv[2]);

    int arraySize = 100;
    int doubling = 0;
    int arrayPosition = 0;
    wordsInFile* wArray = new wordsInFile[arraySize];

    if (myFile.good())
    {
        string wordRead;

        int checkVariable;

        while (!myFile.eof())
        {
            myFile>>wordRead;
            checkVariable = 0;

            if (CommonWord(wordRead) == false)
            {
                if (arrayPosition+1 == arraySize) // arrayPosition will always be one less than the array size
                {
                    arraySize = arraySize*2; //doubling the size of the array
                    wArray = arrayDoubling(wArray,arraySize);
                    doubling++;
                }
                for (int i = 0; i<arrayPosition; i++)
                {
                    if (wordRead.compare(wArray[i].word) == 0) // if a word is a match it will return zero
                    {
                        wArray[i].wordCount++;
                        checkVariable = 1;
                        break;
                    }
                }
                if (checkVariable == 0) // if it is not
                {
                    wArray[arrayPosition].word = wordRead;
                    wArray[arrayPosition].wordCount++;
                    arrayPosition++;
                }
            }
        }
    }

    else
    {
        cout<<"File Did Not Open"<<endl;
    }

    for (int i = 0; i<arraySize; i++)
    {
        sum = sum + wArray[i].wordCount;
    }

    arraySorting(wArray, arraySize, numTop);
    cout<<"#"<<endl;
    cout<<"Array doubled: "<<doubling<<endl;
    cout<<"#"<<endl;
    cout<<"Unique non-common words: "<<arrayPosition<<endl;
    cout<<"#"<<endl;
    cout<<"Total non-common words: "<<sum<<endl;
}
