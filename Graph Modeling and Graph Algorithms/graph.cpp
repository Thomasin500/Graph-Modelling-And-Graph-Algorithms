#include <iostream>
#include <vector>

#include "graph.h"

using namespace std;

struct Vertex {

	int id;
	int distance;
	int neighbors[4]; //up,down,left,right
};

vector<Vertex*> adjacencyList(100); //up to 100 vertices with a max 10x10 input 

void outputVertex(int vertexId) {

	cout << "id: " << adjacencyList[vertexId]->id << " distance: " << adjacencyList[vertexId]->distance;
	cout << endl << "neighbors: ";

	for (int i = 0; i < 4; i++) {

		cout << adjacencyList[vertexId]->neighbors[i] << " " << endl;
	}

	cout << endl << endl;
}

void addEdges(int vertexId, int rows, int cols) {

	if (adjacencyList[vertexId]->distance != 0) {

		//check neighbors
		//up
		if (adjacencyList[vertexId]->id - (rows * adjacencyList[vertexId]->distance) > 0) {

			adjacencyList[vertexId]->neighbors[0] = adjacencyList[vertexId]->id - (rows * adjacencyList[vertexId]->distance);
		}
		else adjacencyList[vertexId]->neighbors[0] = -1;

		//down
		if (adjacencyList[vertexId]->id + (rows * adjacencyList[vertexId]->distance) <= rows * cols) {

			adjacencyList[vertexId]->neighbors[1] = adjacencyList[vertexId]->id + (rows * adjacencyList[vertexId]->distance);
		}
		else adjacencyList[vertexId]->neighbors[1] = -1;

		//left
		if (adjacencyList[vertexId]->id - ((ceil((double) adjacencyList[vertexId]->id / cols) - 1) * rows) - adjacencyList[vertexId]->distance > 0) {

			adjacencyList[vertexId]->neighbors[2] = adjacencyList[vertexId]->id - adjacencyList[vertexId]->distance;
		}
		else adjacencyList[vertexId]->neighbors[2] = -1;

		//right
		if (adjacencyList[vertexId]->id - ((ceil((double)adjacencyList[vertexId]->id / cols) - 1) * rows) + adjacencyList[vertexId]->distance <= cols) {

			adjacencyList[vertexId]->neighbors[3] = adjacencyList[vertexId]->id + adjacencyList[vertexId]->distance;
		}
		else adjacencyList[vertexId]->neighbors[3] = -1;
	}

	else {

		for (int i = 0; i < 4; i++) {

			adjacencyList[vertexId]->neighbors[i] = -1;
		}
	}
}

void fillGraph(int rows, int cols) {

	for (int i = 1; i < rows*cols + 1; i++) {

		addEdges(i, rows, cols);
	}
}

void displayGraph(int rows, int cols) {

	for (int i = 1; i < rows*cols + 1; i++) {

		cout << adjacencyList[i]->id << adjacencyList[i]->distance << endl;
	}
}


void createGraph(int matrix[10][10], int rows, int cols) {

	int dist = 0;

	int id = 1;

	for (int i = 0; i < rows; i++) {

		for (int j = 0; j < cols; j++) {

			adjacencyList[id] = new Vertex;

			adjacencyList[id]->distance = matrix[i][j];

			adjacencyList[id]->id = id;

			id++;
		}
	}
}


