#include <bits/stdc++.h>

using namespace std;
#define V 6

int minTime(int times[], bool included[]) {
    int minimum = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (included[v] == false && times[v] < minimum)
            minimum = times[v], min_index = v;
    }
    return min_index;
}

void printDist(int times[]) {
    cout << "City" << "        " << "Time" << endl;
    for (int i = 0; i < V; i++) {
        cout << i << "           " << times[i] << endl;
    }
}

void dijkstra(int graph[V][V], int source) {
    int times[V];
    bool included[V];

    for (int i = 0; i < V; i++) {
        times[i] = INT_MAX, included[i] = false;
    }

    times[source] = 0;

    for (int c = 0; c < V-1; c++) {
        int u = minTime(times,included);
        // cout << u << "glam" << endl;
        included[u] = true;
        for (int v = 0; v < V; v++)
            if (!included[v] && graph[u][v] && times[u] != INT_MAX && times[u] + graph[u][v] < times[v])
                times[v] = times[u] + graph[u][v];
    }
    cout << "Source : " << source << endl;
    printDist(times);
}

int main() {
    int graph[V][V] = {{0,10,0,0,15,5},
                        {10,0,10,30,0,0},
                        {0,10,0,12,5,0},
                        {0,30,12,0,0,20},
                        {15,0,5,0,0,0},
                        {5,0,0,20,0,0}};
    
    // cout << INT_MAX;
    for (int i = 0; i < V; i++) {
        dijkstra(graph, i);
        cout << endl;
    }
    return 0;
}