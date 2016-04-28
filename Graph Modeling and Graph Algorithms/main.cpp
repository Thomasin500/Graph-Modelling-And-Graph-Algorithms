// Thomas Freeman
// Analysis of Algorithms 
// Project 3: Graph Modeling and Graph Alorithms

#include <sstream>
#include <string>
#include <fstream>
#include <iostream>

#include "graph.h"

using namespace std;

//global variables
int inputMatrix[10][10]; //currently a 10x10 matrix, example is 7x7. expand more or make dynamic?
int rows;
int cols;
ifstream file("C:\\Users\\Thomas\\OneDrive\\School\\Analysis of Algorithms\\Project 3\\smallInput.txt");

void displayMatrix() {

	cout << "Rows: " << rows << " Columns: " << cols << endl << endl;

	for (int i = 0; i < rows; i++) {

		for (int j = 0; j < cols; j++) {

			cout << inputMatrix[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl << endl;
}

void readInput() {

	string line;

	bool dem = true;
	int rowNum = 0;

	if (file.is_open()) {

		while (getline(file, line)) {

			if (dem) {

				rows = line[0] - '0';
				cols = line[2] - '0';				

				dem = false;
			}

			else {

				int realCol = 0;

				for (int i = 0; i < cols * 2; i += 2) {

					inputMatrix[rowNum][realCol] = line[i] - '0';
					realCol++;
				}

				rowNum++;
			}
		}
	}

	else cout << "Cannot Open File";
}

int main() {

	readInput();

	displayMatrix();

	createGraph(inputMatrix, rows, cols);

	addEdges(rows, cols);

	dijkstra(rows, cols);

	cin.ignore();

}


