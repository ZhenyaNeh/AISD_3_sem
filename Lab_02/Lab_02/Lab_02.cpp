#include "stdafx.h"
#include "GraphAdjacencyList.h"
#include "GraphAdjacencyMatrix.h"
#include "GraphEdgeList.h"

int main()
{
    setlocale(LC_ALL, "rus");

    int arr[22][2] = { {1, 2}, {1, 5}, {2, 1}, {2, 7}, {2, 8}, {3, 8}, {4, 6}, {4, 9}, {5, 1}, {5, 6}, {6, 4}, {6, 5}, {6, 9}, {7, 2}, {7, 8}, {8, 2}, {8, 3}, {8, 7}, {9, 4}, {9, 6}, {9, 10}, {10, 9} };

    cout << "_________________СПИСОК_РЕБЕР__________________\n";
    GraphEdgeList firstGraph(10); // Создаем граф с 10вершинами

    for (int i = 0; i < 22; i++)
    {
        int firstParm = arr[i][0];
        int secondParm = arr[i][1];
        firstGraph.addEdge(firstParm, secondParm);
    }

    cout << "BFS (начиная с вершины 1): ";
    firstGraph.BFS(1);

    cout << "DFS (начиная с вершины 1): ";
    firstGraph.DFS(1);

    cout << "\n\n_______________МАТРИЦА_СМЕЖНОСТИ_______________\n";
    GraphAdjacencyMatrix secondGraph(10); // Создаем граф с 10вершинами

    for (int i = 0; i < 22; i++)
    {
        int firstParm = arr[i][0];
        int secondParm = arr[i][1];
        secondGraph.addEdge(firstParm, secondParm);
    }

    cout << "BFS (начиная с вершины 1): ";
    secondGraph.BFS(1);

    cout << "DFS (начиная с вершины 1): ";
    secondGraph.DFS(1);

    cout << "\n\n_______________СПИСОК_СМЕЖГНОСТИ_______________\n";
    GraphAdjacencyList thirtGraph(10); // Создаем граф с 10вершинами

    for (int i = 0; i < 22; i++)
    {
        int firstParm = arr[i][0];
        int secondParm = arr[i][1];
        thirtGraph.addEdge(firstParm, secondParm);
    }

	cout << "BFS (начиная с вершины 1): ";
    thirtGraph.BFS(1);

	cout << "DFS (начиная с вершины 1): ";
    thirtGraph.DFS(1);
}