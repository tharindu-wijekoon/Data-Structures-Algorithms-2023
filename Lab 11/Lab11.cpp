#include <bits/stdc++.h>

using namespace std;

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

int minimumK(int key[], bool mstTree[]) {
	int min = INT_MAX, min_index;

	for (int v = 0; v < 6; v++)
		if (mstTree[v] == false && key[v] < min)
			min = key[v], min_index = v;
	return min_index;
}

void printMST(int parent[], int graph[6][6]) {
	printf("Edge \tWeight\n");
	for (int i = 1; i < 6; i++)
		printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
}


void primMST(int graph[6][6]) {

	int parent[6];
	int key[6];
	bool mstTree[6];

	for (int i = 0; i < 6; i++)
		key[i] = INT_MAX, mstTree[i] = false;
	key[0] = 0;

	parent[0] = -1;

	for (int count = 0; count < 5; count++) {
		int u = minimumK(key, mstTree);
		mstTree[u] = true;

		for (int v = 0; v < 6; v++)			
			if (graph[u][v] && mstTree[v] == false && graph[u][v] < key[v])
				parent[v] = u, key[v] = graph[u][v];
	}

	// print the constructed MST
	printMST(parent, graph);
}

int main() {
	int graph[6][6] = { { 0, 3, 0, 0, 0, 1},
						{ 3, 0, 2, 1, 10, 0 },
						{ 0, 2, 0, 3, 0, 5 },
						{ 0, 1, 3, 0, 5, 0 },
						{ 0, 10, 0, 5, 0, 4 },
                        { 1, 0, 5, 0, 4, 0} };

	primMST(graph);

	return 0;
}