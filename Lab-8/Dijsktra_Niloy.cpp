
#include<stdio.h>
#define INFINITY 9999
#define MAXSIZE 10

void dijkstraAlgo(int graph[MAXSIZE][MAXSIZE], int num, int node)
{
    int cost[MAXSIZE][MAXSIZE], distance[MAXSIZE], pred[MAXSIZE];
    int visit[MAXSIZE], count, minDistance, nextNode;

    for(int i=0; i<num; i++)
    {
        for(int j=0; j<num; j++)
        {
            if(graph[i][j] == 0)
            {
                cost[i][j] = INFINITY;
            }
            else
            {
                cost[i][j] = graph[i][j];
            }
        }
    }

    for(int i=0; i<num; i++)
    {
        distance[i] = cost[node][i];
        pred[i] = node;
        visit[i] = 0;
    }

    distance[node] = 0;
    visit[node] = 1;
    count = 1;

    while(count < num-1)
    {
        minDistance = INFINITY;

        for(int i=0; i<num; i++)
        {
            if(distance[i] < minDistance && !visit[i])
            {
                minDistance = distance[i];
                nextNode = i;
            }
        }
        visit[nextNode] = 1;

        for(int i=0; i<num; i++)
        {
            if(!visit[i])
            {
                if(minDistance+cost[nextNode][i] < distance[i])
                {
                    distance[i] = minDistance+cost[nextNode][i];
                    pred[i] = nextNode;
                }
            }
        }
        count++;
    }

    for(int i=0; i<num; i++)
    {
        if(i!=node)
        {
            printf("\nDistance of node %d = %d", i, distance[i]);
            printf("\nPath = %d", i);

            int j = i;

            do
            {
                j = pred[j];
                printf("<- %d", j);
            }
            while(j!=node);
        }
    }
}

void dijkstraAlgo(int graph[MAXSIZE][MAXSIZE], int num, int node);

int main()
{
    int graph[MAXSIZE][MAXSIZE], num, num2;

    printf("Enter no. of Vertices: ");
    scanf("%d",&num);

    printf("\nEnter the Adjacency Matrix: ");
    for(int i=0; i<num; i++)
    {
        for(int j=0; j<num; j++)
        {
            scanf("%d", &graph[i][j]);
            scanf("%d", &num2);
        }
    }

    dijkstraAlgo(graph, num, num2);

    return 0;
}
