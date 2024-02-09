#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include "Graph.h"

#define SIZE 8

using namespace std;

void Graph::Prims(int startVert)
{
    vector<bool> visited(SIZE, false);

    visited[startVert - 1] = true;
    int currentEdge = 0;
    int x;
    int y;
    while (currentEdge < SIZE - 1)
    {
        int min = INT_MAX;
        x = 0;
        y = 0;

        for (int i = 0; i < SIZE; i++)
        {
            if (visited[i])
            {
                for (int j = 0; j < SIZE; j++)
                {
                    if (!visited[j] && min > graphMatrix[i][j])
                    {
                            min = graphMatrix[i][j];
                            x = i;
                            y = j;
                    }
                }
            }
        }

        cout << x + 1 << " -> " << y + 1 << " = (" << graphMatrix[x][y]<< ")" << endl;
        visited[y] = true;
        currentEdge++;
    }
}

void Graph::Kruskals()
{
    vector<int> connectedVert(SIZE + 1, 0);

    for (int i = 0; i < SIZE; i++)
        connectedVert[i] = i;

    sort(edgeList.begin(), edgeList.end(), [](Edge& a, Edge& b) { return a.weight < b.weight; });

    for (Edge& e : edgeList)
    {
        if (connectedVert[e.start] != connectedVert[e.end])
        {
            cout << e.start << " -> " << e.end << " = (" << e.weight << ")" << endl;

            int oldVert = connectedVert[e.start];
            int newVert = connectedVert[e.end];

            for (int i = 0; i < SIZE; i++)
            {
                if (connectedVert[i] == oldVert)
                    connectedVert[i] = newVert;
            }
        }
    }
}