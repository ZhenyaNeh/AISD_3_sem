#pragma once
#include "stdafx.h"

class Edge
{
public:
	int u, v;

	Edge(int a, int b) : u(a), v(b) {}
};

class GraphEdgeList
{
public:
	int V; // Количество вершин
	vector<Edge> edges; // Список ребер

	GraphEdgeList(int vertices) : V(vertices) {}

	void addEdge(int u, int v)
	{
		edges.emplace_back(u - 1, v - 1);
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

			for (const Edge& edge : edges)
			{
				if (edge.u == u && !visited[edge.v])
				{
					visited[edge.v] = true;
					q.push(edge.v);
				}
				else if (edge.v == u && !visited[edge.u])
				{
					visited[edge.u] = true;
					q.push(edge.u);
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

			for (const Edge& edge : edges)
			{
				if (edge.u == u && !visited[edge.v])
				{
					visited[edge.v] = true;
					s.push(edge.v);
				}
				else if (edge.v == u && !visited[edge.u])
				{
					visited[edge.u] = true;
					s.push(edge.u);
				}
			}
		}
		cout << endl;
	}
};