#pragma once

class Tree;

class World
{
public:

	Tree* TerrainQuadTreeIndexer;

	int WorldSize;

	World(int Bit);
	~World();
};