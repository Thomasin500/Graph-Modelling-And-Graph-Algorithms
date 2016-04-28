#include <vector>
#include <iostream>
#include <queue>
#include <string>
#include <fstream>

using namespace std;

struct Vertex {

	int id;
	int label = 999;
	int distance;
	int neighbors[4]; //up,down,left,right
};

void addEdges(int rows, int cols);

void addNeighbors(int vertexId, int rows, int cols);

void createGraph(int matrix[10][10], int rows, int cols);

void dijkstra(int rows, int cols);

void displayPath(vector<int> path);

int findSmallest(vector<Vertex*> array);

int findSmallestIndex(vector<Vertex*> array);
