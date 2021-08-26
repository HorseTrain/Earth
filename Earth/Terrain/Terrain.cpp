#include "Terrain.h"

#include "TerrainMesh.h"

Terrain::Terrain()
{
	Mesh = new TerrainMesh();
}

Terrain::~Terrain()
{
	delete Mesh;
}

void Terrain::Generate(double x, double z, double scale)
{

}