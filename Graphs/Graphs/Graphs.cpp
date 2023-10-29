#include <iostream>
#include "Graph.h"
#include <list>
#include <cstdlib> //for rand and srand
#include <ctime> //for time   
int main()
{
    srand(time(nullptr));

    int numNodes = 10; //number of nodes

    Graph g(numNodes); 

    for (int i = 0; i < numNodes; i++) //adds random edges between nodes.
    {
        int u = rand() % numNodes;
        int v = rand() % numNodes;
        bool isTwoWay = rand() % 15 == 0;

        g.addEdge(u, v, isTwoWay);
    }

    g.print();

    g.depth(); //perform depth
}

