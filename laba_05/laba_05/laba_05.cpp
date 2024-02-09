#include <iostream>﻿
#include "Graph.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");
    Graph graph;
    cout << "Список ребер остовного дерева и их вес (алгоритм Прима)" << endl;
    graph.Prims(4);
    cout << "\nСписок ребер остовного дерева и их вес (алгоритм Краскала)" << endl;
    graph.Kruskals();
}