#pragma once

#include "..\glm\mat4x4.hpp"

class TerrainMesh;

class Terrain
{
private:

	int VertexWidth;

public:

	TerrainMesh* Mesh;

	Terrain(int VertexWidth);
	~Terrain();

	void Generate(double x, double z, double scale);
	void TransformRawVerticies(glm::dmat4 Transform);
};