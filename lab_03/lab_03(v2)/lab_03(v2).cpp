#include <iostream>
#include <vector>
#include <climits>

#define SIZE 9
using namespace std;

const int INF = INT_MAX;

int minDistance(vector<int>& dist, vector<bool>& visited);
void printSolution(vector<int>& dist, char* graphVertices, char sartChar);
void dijkstra(vector<vector<int>>& graph, int start, char* graphVertices, char sartChar);

int main() 
{
    setlocale(LC_ALL, "ru");
    vector<vector<int>> graph(SIZE, vector<int>(SIZE, 0)); // Матрица смежности

    graph = {
        //	    A	 B	  C    D    E    F    G    H    I  
        /*A*/ { 0,   7,  10,   0,   0,   0,   0,   0,   0},
        /*B*/ { 7,   0,   0,   0,   0,   9,  27,   0,   0},
        /*C*/ {10,   0,   0,   0,  31,   8,   0,   0,   0},
        /*D*/ { 0,	 0,   0,   0,  32,   0,   0,  17,  21},
        /*E*/ { 0,	 0,  31,  32,   0,   0,   0,   0,   0},
        /*F*/ { 0,	 9,   8,   0,   0,   0,   0,  11,   0},
        /*G*/ { 0,  27,	  0,   0,   0,   0,   0,   0,  15},
        /*H*/ { 0,   0,   0,  17,   0,  11,   0,   0,  15},
        /*I*/ { 0,   0,   0,  21,   0,   0,  15,  15,   0}
    };

    char startChar;
    int start{0};
    bool check = false;

    while (!check)
    {
        cout << "Введите начальную вершину от (A - I): ";
        cin >> startChar;
        if (startChar < 'A' || startChar > 'I')
        {
            cout << "Вы ввели не коректные данные, повторите ввод....\n\n";
            continue;
        }
        break;
    }

    char graphVertices[SIZE] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I' };

    for (int i = 0; i < SIZE; i++)
    {
        if (startChar == graphVertices[i])
        {
            start = i;
            break;
        }
    }

    dijkstra(graph, start, graphVertices, startChar);

    return 0;
}

void dijkstra(vector<vector<int>>& graph, int start, char* graphVertices, char sartChar)
{
    vector<int> dist(SIZE, INF);
    vector<bool> visited(SIZE, false);

    dist[start] = 0; 

    for (int count = 0; count < SIZE - 1; count++)
    {
        int u = minDistance(dist, visited); 

        visited[u] = true; 

        
        for (int v = 0; v < SIZE; v++)
        {
            if (!visited[v] && graph[u][v] && dist[u] != INF && (dist[u] + graph[u][v] < dist[v]))
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printSolution(dist, graphVertices, sartChar);
}

int minDistance(vector<int>& dist, vector<bool>& visited)
{
    int min = INF, minIndex;
    for (int i = 0; i < SIZE; i++)
    {
        if (!visited[i] && dist[i] <= min)
        {
            min = dist[i];
            minIndex = i;
        }
    }
    return minIndex;
}

void printSolution(vector<int>& dist, char* graphVertices, char sartChar)
{
    cout << "Вершина\tРасстояние от начальной вершины" << endl;
    for (int i = 0; i < SIZE; i++)
    {
        cout << sartChar << " -> " << graphVertices[i] << "\t" << dist[i] << endl;
    }
}