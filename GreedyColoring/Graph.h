#ifndef GRAPH_H
#define GRAPH_H
#include <list>
#include "Vertex.h"

class Graph
{
public:
	void makeEdge(char key, char insertKey); //makes an edge based on two vertex keys
	void makeVertex(char key); //makes a single vertex
	void printGraph(); //prints the graph
	void greedyColor(); //greedy coloring algorithm
	void printColors(); //prints the colors associated with each vertex
private:
	const static int maxColors = 256; //256 levels of color
	std::list<Vertex*> adjList;
	Vertex* vertex;
};

#endif