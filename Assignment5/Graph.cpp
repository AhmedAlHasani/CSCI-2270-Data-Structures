/*
Name: Ahmed AlHasani
HW5
Instructor :Samantha Molnar
I helped a lot of students, so please be aware of this.
I spoke with Sam about this, and I asked each student to include my name if they used my code
*/
#include "Graph.h"
#include <stddef.h>
#include <stdlib.h>
#include <queue>
using namespace std;

Graph::Graph()
{
    //ctor
}

Graph::~Graph()
{
    //dtor
}

void Graph::addEdge(std::string v1, std::string v2, int weight)
{
    for (int i = 0; i<vertices.size(); i++)
    {
        if (vertices[i].name==v1)
        {
            for(int j = 0; j<vertices.size(); j++)
            {
                if(vertices[j].name==v2 && i!=j)
                {
                    adjVertex av;
                    av.v=&vertices[j];
                    av.weight=weight;
                    vertices[i].adj.push_back(av);
                }
            }
        }
    }
}


void Graph::addVertex(std::string n)
{
    bool found=false;
    for (int i = 0; i<vertices.size(); i++)
    {
        if(vertices[i].name==n)
        {
            found = true;
        }
    }
    if (!found)
    {
        vertex v;
        v.name = n;
        vertices.push_back(v);
    }
}

void Graph::displayEdges()
{
    for (int i = 0; i<vertices.size(); i++)
    {
        std::cout<< vertices[i].district<< ":" <<vertices[i].name<<"-->";
        for (int j = 0; j<vertices[i].adj.size(); j++)
        {
            std::cout<<vertices[i].adj[j].v->name;
            if(j != vertices[i].adj.size()-1)
                cout<<"***";
        }
        std::cout<<std::endl;
    }
}

vertex* Graph::findVertex(std::string name) //search for a vertex
{
    vertex* foundVertex = NULL;
    bool accessed = true;
    for (int i = 0; i<vertices.size(); i++)
    {
        if(vertices[i].name == name)
        {
            return &vertices[i];
            accessed = false;
        }
    }
    if (accessed == true)
    {
        cout<<"One or more cities doesn't exist"<<endl;
        return foundVertex;
    }
    //return foundVertex;
}

void Graph::BFTraversalLabel(std::string city, int distID) //breadth search (level or neighboring directly)
{
    vertex* v = findVertex(city); //reminder: this is a pointer to a struct
    if (v->name == city)
    {
        v->district = distID;
        v->visited = true;
    }
    for (int j = 0; j<v->adj.size(); j++)
    {
        if (v->adj[j].v->visited != true)
        {
            v->adj[j].v->district = distID;
            v->adj[j].v->visited = true;
        }

        vertex* v2 = v->adj[j].v;

        for (int z = 0; z<v2->adj.size(); z++)
        {
            if (v2->adj[z].v->visited != true)
            {
                v2->adj[z].v->district = distID;
                v2->adj[z].v->visited = true;
            }
        }
    }
}

void Graph::assignDistricts() //go through the vertices vector and assign districts
{
    int distID = 0;
    for (int i = 0; i <vertices.size(); i++)
    {
        if (vertices[i].visited != true) //if the vertex is not visited
        {
            distID++;
            BFTraversalLabel(vertices[i].name,distID);
            vertices[i].visited = true;
        }
    }
}

void Graph::shortestPath(std::string startingCity, std::string endingCity)
{
    vertex* v1 = findVertex(startingCity);
    vertex* v2 = findVertex(endingCity);

    if (v1 != NULL and v2 != NULL)
    {
        int distance = 0;
        int minDistance = 0;
        vector<vertex*> solved;
        vertex* parent = NULL;
        vertex* s = NULL;
        vertex* solvedVertex = NULL;

        if(v1->district == -1 || v2->district == -1 and v1 != NULL and v2!= NULL)
            cout<<"Please identify the districts before checking distances"<<endl;
        else if (v1 != NULL and v2 != NULL and v1->district == v2->district)
        {
            for (int i = 0; i<vertices.size(); i++)
            {
                vertices[i].visited = false;
                vertices[i].parent = NULL;
            }

            if(v1->district == v2->district)
            {
                v1->distance = 0;
                v1->visited = true;
                solved.push_back(v1);
                while (v2->visited != true)
                {
                    minDistance = 150;
                    solvedVertex = NULL;
                    for (int x = 0; x<solved.size(); x++)
                    {
                        s = solved[x];
                        for(int y = 0; y<s->adj.size(); y++)
                        {
                            if(s->adj[y].v->visited != true)
                            {
                                distance = s->distance + s->adj[y].v->distance;
                                if (distance < minDistance)
                                {
                                    solvedVertex = s->adj[y].v;
                                    minDistance = distance;
                                    parent = s;
                                }
                            }
                        }
                    }
                    solvedVertex->distance = minDistance;
                    solvedVertex->parent = parent;
                    solvedVertex->visited = true;
                    solved.push_back(solvedVertex);
                }
                //cout<<minDistance;
                vertex* printVertex = solvedVertex;
                vector<string> stringStore;
                string storeVector;
                int a,b = 0;
                while (printVertex!=NULL)
                {
                    storeVector = printVertex->name;
                    stringStore.push_back(storeVector);
                    //cout<<","<<printVertex->name;
                    printVertex = printVertex->parent;
                    a++;
                }
                b = a-1;
                //cout<<b<<endl;
                cout<<minDistance;
                while (-1!=b)
                {
                    cout<<","<<stringStore[b];
                    b--;
                }
                cout<<endl;
            }
        }
            else
                cout<<"No safe path between cities"<<endl;

    }
}
