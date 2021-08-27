#include "World.h"
#include "../Tools/Tree.h"

World::World(int Bit)
{
	this->WorldSize = 1ULL << Bit;
	this->TerrainQuadTreeIndexer = new Tree(2,this->WorldSize);
}

World::~World()
{
	delete TerrainQuadTreeIndexer;
}