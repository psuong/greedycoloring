#ifndef VERTEX_H
#define VERTEX_H
#include <list>
#include <iostream>

class Vertex
{
public:
	Vertex(char key)
	{
		colorIndex = -1;
		isColored = false;
		vertexKey = key;
	}
	void setColor(int color); //sets the color and sets is colored to true
	char getKey() { return vertexKey; } //returns the key of the vertex
	void pushNeighbor(Vertex* vertex); //adds vertex to list of neighbors

	//getters to get the front and end of list of neighbors
	std::list<Vertex*>::iterator getStart() { return Neighbors.begin(); }
	std::list<Vertex*>::iterator getEnd() { return Neighbors.end(); }

	void printNeighbors();
	int getColor() { return colorIndex; }
	bool getIsColored() { return isColored; }

private:
	int colorIndex;
	bool isColored;
	char vertexKey;
	std::list<Vertex*> Neighbors;

};

#endif