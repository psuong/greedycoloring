#include "Graph.h"

//makes the vertex
void Graph::makeVertex(char key)
{
	vertex = new Vertex(key);
	adjList.push_back(vertex);
}

//connects two vertices together
void Graph::makeEdge(char key, char insertKey)
{
	std::list<Vertex*>::iterator begin = adjList.begin();
	std::list<Vertex*>::iterator end = adjList.end();
	std::list<Vertex*>::iterator begin2 = begin;
	std::list<Vertex*>::iterator end2 = end;

	for (begin; begin != end; begin++)
	{
		if ((*begin)->getKey() == key)
		{
			for (begin2; begin2 != end2; begin2++)
			{
				if ((*begin2)->getKey() == insertKey)
				{
					(*begin)->pushNeighbor(*begin2);
					begin2 = adjList.begin(); //resetting the iterator
					break;
				}
			}
		}
	}
}

//greedy algorithm coloring
void Graph::greedyColor()
{
	int color = 0;
	std::list<Vertex*>::iterator begin = adjList.begin();
	std::list<Vertex*>::iterator end = adjList.end();
	std::list<Vertex*>::iterator localStart;
	std::list<Vertex*>::iterator localEnd;
	std::list<int> colorList;
	(*begin)->setColor(color);
	
	for (begin; begin != end; begin++)
	{
		localStart = (*begin)->getStart();
		localEnd = (*begin)->getEnd();
		for (localStart; localStart != localEnd; localStart++)
		{
			if ((*localStart)->getIsColored()) //checks if the vertex is colored
			{
				colorList.push_back((*localStart)->getColor()); //pushes colors into a temporary list
			}
		}
		for (int i = 0; i < maxColors; i++)
		{
			if (std::find(colorList.begin(), colorList.end(), i) == colorList.end())
			{
				//std::cout << "Color not found" << std::endl;
				(*begin)->setColor(i);
				colorList.clear(); //clears the list of colors for the next vertex to use
				break;
			}
		}
	}
}

//prints the graph
void Graph::printGraph()
{
	std::list<Vertex*>::iterator start = adjList.begin();
	std::list<Vertex*>::iterator end = adjList.end();
	for (start; start != end; start++)
	{
		std::cout << "Key: " << (*start)->getKey() << "\tNeighbors: "; 
		(*start)->printNeighbors();
		std::cout << std::endl;
	}
}

void Graph::printColors()
{
	std::list<Vertex*>::iterator start = adjList.begin();
	std::list<Vertex*>::iterator end = adjList.end();
	for (start; start != end; start++)
	{
		std::cout << "Colors: " << (*start)->getColor() << std::endl;
	}
}