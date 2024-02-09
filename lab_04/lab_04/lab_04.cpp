#include <iostream>
#include <vector>

using namespace std;

#define COUNT_OF_GRAPH_VERTICES  6
#define INF INT_MAX

int main()
{
	setlocale(LC_ALL, "ru");

	vector<vector<int>> graph(COUNT_OF_GRAPH_VERTICES, vector<int>(COUNT_OF_GRAPH_VERTICES, INF));
	vector<vector<int>> graphWays(COUNT_OF_GRAPH_VERTICES, vector<int>(COUNT_OF_GRAPH_VERTICES, 0));

	graph =
	{
		{ 0,  28,  21,  59, 12,  27},
		{ 7,   0,  24, INF, 21,   9},
		{ 9,  32,   0,  13, 11, INF},
		{ 8, INF,   5,   0, 16, INF},
		{14,  13,  15,  10,  0,  22},
		{15,  18, INF, INF,  6,   0}
	};

	graphWays =
	{
		{0, 2, 3, 4, 5, 6},
		{1, 0, 3, 4, 5, 6},
		{1, 2, 0, 4, 5, 6},
		{1, 2, 3, 0, 5, 6},
		{1, 2, 3, 4, 0, 6},
		{1, 2, 3, 4, 5, 0}
	};

	for (int k = 0; k < COUNT_OF_GRAPH_VERTICES; k++)
	{
		for (int i = 0; i < COUNT_OF_GRAPH_VERTICES; i++)
		{
			for (int j = 0; j < COUNT_OF_GRAPH_VERTICES; j++)
			{
				if (graph[i][k] != INF && graph[k][j] != INF)
				{
					if ((graph[i][k] + graph[k][j]) < graph[i][j])
					{
						graph[i][j] = graph[i][k] + graph[k][j];
						graphWays[i][j] = graphWays[i][k];
					}
				}
			}
		}
	}

	cout << "Матрица кратчайших путей:" << endl;
	for (int i = 0; i < COUNT_OF_GRAPH_VERTICES; i++)
	{
		for (int j = 0; j < COUNT_OF_GRAPH_VERTICES; j++)
		{
			if (graph[i][j] == INF) {
				cout << "INF ";
			}
			else
			{
				cout << graph[i][j] << '\t';
			}
		}
		cout << "\n\n";
	}
	cout << endl;

	cout << "Матрица последовательности вершин:" << endl;
	for (int i = 0; i < COUNT_OF_GRAPH_VERTICES; i++)
	{
		for (int j = 0; j < COUNT_OF_GRAPH_VERTICES; j++)
		{
			cout << graphWays[i][j] << ' ';
		}
		cout << endl;
	}

	return 0;
}