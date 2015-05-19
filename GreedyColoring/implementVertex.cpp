#include "Vertex.h"

void Vertex::pushNeighbor(Vertex* vertex)
{
	Neighbors.push_back(vertex);
}

void Vertex::setColor(int color)
{
	colorIndex = color;
	isColored = true;
}

void Vertex::printNeighbors()
{
	std::list<Vertex*>::iterator start = getStart();
	std::list<Vertex*>::iterator end = getEnd();

	for (start; start != end; start++)
	{
		std::cout << (*start)->getKey() << " ";
	}
}