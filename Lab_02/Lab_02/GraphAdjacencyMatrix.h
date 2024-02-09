#pragma once
#include "stdafx.h"

class GraphAdjacencyMatrix
{
public:
	int V; // Количество вершин
	vector<vector<int>> adjMatrix; // Матрица смежности

	GraphAdjacencyMatrix(int vertices) : V(vertices)
	{
		// Инициализируем матрицу смежности как квадратную матрицу размером V x V
		adjMatrix.resize(V, vector<int>(V, 0));
	}

	void addEdge(int u, int v)
	{
		// Добавляем ребро между вершинами u и v
		adjMatrix[u - 1][v - 1] = 1;
		adjMatrix[v - 1][u - 1] = 1; // Граф неориентированный, поэтому добавляем обратное ребро
	}


	void BFS(int startVertex) 
	{
		startVertex--;
		vector<bool> visited(V, false);
		queue<int> q;

		visited[startVertex] = true;
		q.push(startVertex);

		while (!q.empty())
		{
			int u = q.front();
			q.pop();
			cout << u + 1 << " ";

			for (int v = 0; v < V; ++v)
			{
				if (adjMatrix[u][v] && !visited[v])
				{
					visited[v] = true;
					q.push(v);
				}
			}
		}
		cout << endl;
	}

	void DFS(int startVertex)
	{
		startVertex--;
		vector<bool> visited(V, false);
		stack<int> s;

		visited[startVertex] = true;
		s.push(startVertex);

		while (!s.empty())
		{
			int u = s.top();
			s.pop();
			cout << u + 1 << " ";

			for (int v = 0; v < V; ++v)
			{
				if (adjMatrix[u][v] && !visited[v])
				{
					visited[v] = true;
					s.push(v);
				}
			}
		}
		cout << endl;
	}
};