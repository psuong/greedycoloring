#include <iostream>
#include "Graph.h"

int main()
{
	Graph graph = Graph();
	graph.makeVertex('A');
	graph.makeVertex('B');
	graph.makeVertex('C');
	graph.makeVertex('D');
	graph.makeVertex('E');

	graph.makeEdge('A', 'B');
	graph.makeEdge('A', 'C');

	graph.makeEdge('B', 'A');
	graph.makeEdge('B', 'C');
	graph.makeEdge('B', 'D');

	graph.makeEdge('C', 'A');
	graph.makeEdge('C', 'B');
	graph.makeEdge('C', 'D');

	graph.makeEdge('D', 'B');
	graph.makeEdge('D', 'C');
	graph.makeEdge('D', 'E');
	
	graph.makeEdge('E', 'B');
	graph.makeEdge('E', 'C');
	graph.makeEdge('E', 'D');

	graph.printGraph();

	graph.greedyColor();
	graph.printColors();
}