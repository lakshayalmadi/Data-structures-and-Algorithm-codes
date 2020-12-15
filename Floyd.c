#include<stdio.h>

#define V 7
#define INF 99999

void printSolution(int dist[][V]);

void floydWarshall (int graph[][V])
{
  
    int dist[V][V], i, j, k;
    
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            dist[i][j] = graph[i][j];
  
    for (k = 0; k < V; k++)
    {
        
        for (i = 0; i < V; i++)
        {
            
            
            for (j = 0; j < V; j++)
            {
                
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    
    printSolution(dist);
}

void printSolution(int dist[][V])
{
    printf ("The following matrix shows the shortest distances"
            " between every pair of vertices \n");
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (dist[i][j] == INF)
                printf("%7s", "INF");
            else
                printf ("%7d", dist[i][j]);
        }
        printf("\n");
    }
}

int main()
{
  
                      int graph[V][V] = { {0,   3,  6, INF, INF, INF, INF},
                                          {INF, 0,  2,  4,  INF, INF, INF},
                                          {INF, INF, 0, 1, 4, 2, INF},
                                          {INF, INF, INF, 0, INF, INF, 4},
                                          {INF, INF, INF, INF, 0, 2, 1},
                                          {INF, INF, INF, INF, INF, 0, 1},
                                          {INF, INF, INF, INF, INF, INF, 0}
                                        };
  
    floydWarshall(graph);
    return 0;
}
