#include <iostream>
#include "string"

#define SIZE 9

using namespace std;

int main()
{
	int graphMatrix[SIZE][SIZE] = {
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

	char graphVertices[SIZE] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I' };

	int d[SIZE]; // минимальное расстояние
	int v[SIZE]; // посещенные вершины
    int temp, minIndex{0}, min;
	int begin_index = 0;

	//Инициализация вершин и расстояний
	for (int i = 0; i < SIZE; i++)
	{
		d[i] = 10000;
		v[i] = 1;
	}
	d[begin_index] = 0;

    while (minIndex < 10000) 
    {
        minIndex = 10000;
        min = 10000;
        for (int i = 0; i < SIZE; i++)
        { 
            if ((v[i] == 1) && (d[i] < min))
            { 
                min = d[i];
                minIndex = i;
            }
        }
       
        if (minIndex != 10000)
        {
            for (int i = 0; i < SIZE; i++)
            {
                if (graphMatrix[minIndex][i] > 0)
                {
                    temp = min + graphMatrix[minIndex][i];
                    if (temp < d[i])
                    {
                        d[i] = temp;
                    }
                }
            }
            v[minIndex] = 0;
        }
    }

    printf("\nКратчайшие расстояния до вершин: \n");
    for (int i = 0; i < SIZE; i++)
        printf("%5d ", d[i]);

}