#include "Terrain.h"
#include "TerrainMesh.h"

Terrain::Terrain(int VertexWidth)
{
	this->VertexWidth = VertexWidth;

	Mesh = new TerrainMesh();
}

Terrain::~Terrain()
{
	delete Mesh;
}

void Terrain::Generate(double x, double z, double scale)
{
	for (int x = 0; x < VertexWidth; ++x)
	{
		for (int z = 0; z < VertexWidth; ++z)
		{
			glm::dvec3 base = { x,0,z };

			Mesh->RawVertacies.push_back({ base + glm::dvec3(0,0,0) });
			Mesh->RawVertacies.push_back({ base + glm::dvec3(1,0,0) });
			Mesh->RawVertacies.push_back({ base + glm::dvec3(1,0,1) });
			Mesh->RawVertacies.push_back({ base + glm::dvec3(0,0,1) });
		}
	}
}

glm::dvec4 TransformVec3(glm::dmat4 Transform, glm::dvec3 Source)
{
	return Transform * glm::vec4(Source, 1);
}

void Terrain::TransformRawVerticies(glm::dmat4 Transform)
{
	Mesh->TransformedVerticies = std::vector<TransformedVertex>();

	for (int i = 0; i < Mesh->RawVertacies.size(); ++i)
	{
		TerrainVertex _terrainVertex = Mesh->RawVertacies[i];

		glm::dvec3 tPosition = TransformVec3(Transform, _terrainVertex.Position);
		glm::dvec3 tNormal = TransformVec3(Transform, _terrainVertex.Normal);

		Mesh->TransformedVerticies.push_back({tPosition, tNormal});
	}
}