#pragma once

class TerrainMesh;

class Terrain
{
public:

	TerrainMesh* Mesh;

	Terrain();
	~Terrain();

	void Generate(double x, double z, double scale);
};