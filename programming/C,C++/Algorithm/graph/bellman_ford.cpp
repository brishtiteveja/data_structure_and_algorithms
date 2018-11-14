#include <bits/stdc++.h>

struct edge {
    int src, dest, weight;
};

struct Graph {
    int V, E;
    struct Edge* edge;
};

struct Graph* createGraph(int V, int E)
{
    struct Graph* graph = new Graph;
    graph->V = V;
    graph->E = E;
    graph->edge = new edge[E];
    return graph;
}

void BellmanFord(struct Graph* graph, int src)
{
    int V = graph->V;
    int E = graph->E;
    int dist[V];

    // initialize distances from src to all other vertices as INFINITE
    for(int i=0; i<V; i++)
    {
        dist[i] = INT_MAX;
    }
    dist[src] = 0;

    // Relax edge |V| - 1 times.
    // iteration i finds the shortest path with length i;
    for(int i=1; i <= V-1; i++) 
    {
        for(int j=0; j<E; j++)
        {
            int u = graph->edge[j].src;
            int v = graph->edge[j].dest;
            int weight = graph->edge[j].weight;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }

    for(int j=0; j<E; j++)
    {
        int u = graph->edge[j].src;
        int v = graph->edge[j].dest;
        int weight = graph->edge[j].weight;
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
            printf("Graph contains negative weight cycle"); 
    }
}
