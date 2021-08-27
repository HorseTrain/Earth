#include "TerrainMesh.h"
#include "..\..\External\glew\glew.h"

TerrainMesh::TerrainMesh()
{

}

TerrainMesh::~TerrainMesh()
{
	Deload();
}

void TerrainMesh::Deload()
{
	if (VBO == UINT_MAX)
		glDeleteBuffers(1, &VBO);
}

void TerrainMesh::Upload()
{
	Deload();

	glGenBuffers(1,&VBO);

}