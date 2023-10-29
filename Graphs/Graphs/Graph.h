#pragma once
#include <iostream>
#include <list>
#include <vector>

using namespace std;

class Graph
{
public:
    list<int>* adjList; //adjacency list.
    int j;

    Graph(int v) 
    {
        adjList = new list<int>[v];
        j = v; //number of vertices.
    }

    void addEdge(int u, int v, bool tw) //add edge is function to be used to add edges between two vertices.
    {
        adjList[u].push_back(v);
        if (tw) 
        {
            adjList[v].push_back(u);
        }
    }

    void print() 
    {
        for (int i = 0; i < j; i++) 
        {
            cout << i << "-->";
            for (auto it : adjList[i]) 
            {
                cout << it << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    void depth(int startNode, vector<bool>& visited) //helper function for depth.
    {
        visited[startNode] = true;
        cout << "Visited Node: " << startNode << endl;

        for (auto it : adjList[startNode]) 
        {
            if (!visited[it]) 
            {
                depth(it, visited);
            }
        }
    }

    void depth() //helper function for depth that starts the depth function from a spesific node.
    {
        vector<bool> visited(j, false);
        cout << "Depth:" << endl;
        for (int i = 0; i < j; i++) 
        {
            if (!visited[i]) 
            {
                depth(i, visited);
            }
        }
    }
};


