#include <bits/stdc++.h>

using namespace std;

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

// function to find the node with minimum weighted edge from the selected edge
int minimumK(int key[], bool mstTree[]) {
	// variables to store the minimum value available and index of the minimum value node
	int min = INT_MAX, min_index;

	// iterating through each node to find the node with minimum weight 
	for (int v = 0; v < 6; v++)
		if (mstTree[v] == false && key[v] < min)
			min = key[v], min_index = v;
	return min_index; //returning the node with minimum weight
}

// function to print the MST
void printMST(int parent[], int graph[6][6]) {
	printf("Edge \tWeight\n");
	for (int i = 1; i < 6; i++)
		printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
}

void primMST(int graph[6][6]) {

	int parent[6]; // array to store the parent node of each new node to the mst tree
	int key[6]; // array to store the minimum weight to reach the each node from parent node.
	bool mstTree[6]; // array to store whether the node is in MST

	// initialising arrays
	for (int i = 0; i < 6; i++)
		key[i] = INT_MAX, mstTree[i] = false;
	key[0] = 0; // setting the starting node
	parent[0] = -1; // setting the parent of start node as -1 since it does not have a parent node

	// iterating through all nodes to build the MST
	for (int count = 0; count < 5; count++) {
		int u = minimumK(key, mstTree); 
		mstTree[u] = true;

		for (int v = 0; v < 6; v++)			
			if (graph[u][v] && mstTree[v] == false && graph[u][v] < key[v])
				parent[v] = u, key[v] = graph[u][v];
	}

	// print the MST
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
