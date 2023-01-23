#include <bits/stdc++.h>
using namespace std;
class Edge{
public:
    int u;//start vertex of edge
    int v;//end vertex of edge
    int w;//weight of the edge
};
class Graph{
public:
    int v;//Total number of vertices in the graph
    int e;//total number of edges in the graph
    Edge *edge;//Array of edges
};
//Creating graph using Node pointer func
Graph *createGraph(int v,int e){
    Graph *graph=new Graph;
    graph->v=v;
    graph->e=e;
    graph->edge=new Edge[e];
    return  graph;

}
void printArr(int Arr[],int n){
    for(int i=0; i<n; i++){
        cout<<" "<<Arr[i];
    }
    cout<<endl;
}
void BellmanFord(Graph *graph,int u){
    int v=graph->v;
    int e=graph->e;
    int dist[v];
    for(int i=0; i<v; i++){
        dist[i]=INT_MAX;
    }
    dist[u]=0;
    for(int i=1; i<=v-1; i++){
        for(int j=0; j<e; j++){
            int u=graph->edge[j].u;
            int v=graph->edge[j].v;
            int w=graph->edge[j].w;
            if(dist[u]!=INT_MAX && dist[u]+w<dist[v]){
                dist[v]=dist[u]+w;
            }
        }
    }
    for(int i=0; i<e; i++){
        int u=graph->edge[i].u;
        int v=graph->edge[i].v;
        int w=graph->edge[i].w;
        if(dist[u]!=INT_MAX && dist[u]+w<dist[v]){
            cout<<"Graph contains negative cycle";
            return;
        }

    }
    printArr(dist,v);
}


int main() {
   int v=5;
   int e=8;

   Graph *graph= createGraph(v,e);

    graph->edge[0].u = 0;
    graph->edge[0].v = 1;
    graph->edge[0].w = -1;


    graph->edge[1].u = 0;
    graph->edge[1].v = 2;
    graph->edge[1].w = 4;

    graph->edge[2].u = 1;
    graph->edge[2].v = 2;
    graph->edge[2].w = 3;


    graph->edge[3].u = 1;
    graph->edge[3].v = 3;
    graph->edge[3].w = 2;


    graph->edge[4].u = 1;
    graph->edge[4].v = 4;
    graph->edge[4].w = 2;

    graph->edge[5].u = 3;
    graph->edge[5].v = 2;
    graph->edge[5].w = 5;

    graph->edge[6].u = 3;
    graph->edge[6].v = 1;
    graph->edge[6].w = 1;

    graph->edge[7].u = 4;
    graph->edge[7].v = 3;
    graph->edge[7].w = -3;
    BellmanFord(graph,0);



}

