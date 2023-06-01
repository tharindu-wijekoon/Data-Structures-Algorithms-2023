#include <bits/stdc++.h>

using namespace std;
#define V 6

//function to give the return the city with minimum time
int minTime(int times[], bool included[]) {
    int minimum = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (included[v] == false && times[v] < minimum)
            //to get the city with minimum time when iterating
            minimum = times[v], min_index = v;
    }
    return min_index;
}

//function to print the minimum times
void printDist(int times[]) {
    cout << "City" << "        " << "Time" << endl;
    for (int i = 0; i < V; i++) {
        cout << i << "           " << times[i] << endl;
    }
}

void dijkstra(int graph[V][V], int source) {
    int times[V]; //stores the minimum times
    bool included[V]; //stores if the city is already visited
    
    //to initiate everything as the maximum
    for (int i = 0; i < V; i++) {
        times[i] = INT_MAX, included[i] = false;
    }
    
    //store the time of the source as 0
    times[source] = 0;
    
    //getting the minimum times
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
