#include "graph.h"

vector<Vertex*> adjacencyList(100); //up to 100 vertices with a max 10x10 input 

int findSmallest(vector<Vertex*> array) {

	int min = 999;
	int index = 0;
	
	for (int i = 0; i < array.size(); i++) {
		
		if (array[i]->label < min) {

			min = array[i]->label;
			index = array[i]->id;
		}
	}

	return index;
}

int findSmallestIndex(vector<Vertex*> array) {

	int min = 999;
	int index = 0;

	for (int i = 0; i < array.size(); i++) {

		if (array[i]->label < min) {

			min = array[i]->label;
			index = i;
		}
	}

	return index;
}

void displayPath(vector<int> path) {

	vector<string> output;

	reverse(path.begin(), path.end());

	Vertex current;
	Vertex next;
	
	for (int i = 1; i < path.size(); i++) {
		
		current = *adjacencyList[path[i-1]];
		next = *adjacencyList[path[i]];

		if (current.neighbors[0] == next.id) {

			output.push_back("N ");
		}

		if (current.neighbors[1] == next.id) {

			output.push_back("S ");
		}

		if (current.neighbors[2] == next.id) {

			output.push_back("W ");
		}

		if (current.neighbors[3] == next.id) {

			output.push_back("E ");
		}		
			
	}

	cout << "Solution: " << endl;

	for (int i = 0; i < output.size(); i++) {

		cout << output[i];
	}
}



//Graph Traversal Algorithm for Jumping Jim Solution
//use priority queue for choosing vertices
void dijkstra(int rows, int cols) {

	//create priority queue 
	vector<Vertex*> pq;

	//path vector, stores ids of vertices
	vector<int> solution(100);

	//set root node
	adjacencyList[1]->label = 0;

	//push all nodes to PQ with root node on top
	for (int i = 1; i < rows*cols + 1; i++) {
		
		pq.push_back(adjacencyList[i]);
	}

	Vertex current = *adjacencyList[1];

	//run algorithm
	while (current.id != adjacencyList[rows*cols]->id) {

		//find smallest
		current = *adjacencyList[findSmallest(pq)];

		//remove smallest from pq
		int smallestIndex = findSmallestIndex(pq);
		pq.erase(pq.begin() + smallestIndex);

		//check neighbors
		for (int i = 0; i < 4; i++) {

			//check neighbor exists
			if (adjacencyList[current.id]->neighbors[i] != -1) {

				//compare labels
				if (adjacencyList[adjacencyList[current.id]->neighbors[i]]->label > current.label + current.distance) {

					//update label to totalDistance + distance to neighbor
					adjacencyList[adjacencyList[current.id]->neighbors[i]]->label = current.label + current.distance;
					//back link to find path
					solution[adjacencyList[current.id]->neighbors[i]] = current.id;
				}
			}
		}
	}	

	//build solution path
	vector<int> path;

	while (solution[current.id]) {	

		path.push_back(current.id);
		current.id = solution[current.id];
	}
	path.push_back(current.id);

	displayPath(path);
}

void addNeighbors(int vertexId, int rows, int cols) {

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

void addEdges(int rows, int cols) {

	for (int i = 1; i < rows*cols + 1; i++) {

		addNeighbors(i, rows, cols);
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


