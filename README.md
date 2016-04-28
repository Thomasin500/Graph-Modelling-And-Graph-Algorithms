# Graph Modelling And Graph Algorithms

This program takes in a text file with a grid of integers such as:

3 3 \n
2 1 0
0 1 1
1 2 0

Where the first 2 on the top row correspond to the number of rows and columns, respectively.

The body of the grid represents a trampoline where, starting from the top left, the gymnast is 
able to move up, down, left, or right as many spaces as the label of the square he is on without falling off the grid.
The goal is to reach the bottom left of the grid in as few moves as possible.

The program outputs the solution as a list of moves as directions.

For instance the solution to the above grid is:

S: (1,3) -> (1,1)

E: (1,1) -> (2,1)

N: (2,1) -> (2,3)

S: (2,3) -> (2,2)

E: (2,2) -> (3,2)

S: (3,2) -> (3,3)

Total Solution: S E N S E S

The matrix is first loaded into the program as a 2d array according to the input. The matrix is then transformed into an 
adjacency list representation of a graph.

The graph is then traversed according to a modified version of Dijkstra's Algorithm until the goal is reached.

The path is the outputted to the console and also written to a local output.txt file.
