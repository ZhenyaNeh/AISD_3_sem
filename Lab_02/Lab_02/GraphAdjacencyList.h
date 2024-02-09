#pragma once
#include "stdafx.h"

class GraphAdjacencyList
{
public:
	int V; // Количество вершин
	vector<vector<int>> adj; // Списки смежности

	GraphAdjacencyList(int vertices) : V(vertices)
	{
		adj.resize(V);
	}

	void addEdge(int u, int v)
	{
		adj[u - 1].push_back(v - 1);
		adj[v - 1].push_back(u - 1);
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

			for (int v : adj[u])
			{
				if (!visited[v])
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

			for (int v : adj[u])
			{
				if (!visited[v])
				{
					visited[v] = true;
					s.push(v);
				}
			}
		}
		cout << endl;
	}
};