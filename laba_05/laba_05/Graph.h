#pragma once
#include <iostream>
#include <vector>
#define INF INT_MAX
#define SIZE 8

using namespace std;

struct Edge
{
	int start;
	int end;
	int weight;
};

class Graph
{
private:
	int graphMatrix[SIZE][SIZE] = {
		{INF,   2, INF,   8,   2, INF, INF, INF},
		{  2, INF,   3,  10,   5, INF, INF, INF},
		{INF,   3, INF, INF,  12, INF, INF,   7},
		{  8,  10, INF, INF,  14,   3,   1, INF},
		{  2,   5,  12,  14, INF,  11,   4,   8},
		{INF, INF, INF,   3,  11, INF,   6, INF},
		{INF, INF, INF,   1,   4,   6, INF,   9},
		{INF, INF,   7, INF,   8, INF,   9, INF}
	};

	vector <Edge> edgeList = {
	{1, 2, 2}, {1, 4, 8}, {7, 5, 4}, {1, 5, 2},
	{2, 3, 3}, {2, 5, 5}, {2, 4, 10}, {3, 5, 12},
	{3, 8, 7}, {4, 5, 14}, {4, 6, 3}, {4, 7, 1},
	{5, 8, 8}, {6, 7, 6}, {7, 8, 9}, {5, 6, 11}
	};

public:
	void Prims(int startVert);
	void Kruskals();
};