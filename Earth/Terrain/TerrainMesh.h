#pragma once

#include <vector>
#include "../glm/vec3.hpp"
#include "../glm/mat4x4.hpp"
#include "inttypes.h"

struct TerrainVertex
{
	glm::dvec3 Position;
	glm::dvec3 Normal;
};

struct TransformedVertex
{
	glm::vec3 TransformedPosition;
	glm::vec3 TransformedNormal;
};

class TerrainMesh
{
private:

	uint32_t VBO = UINT_MAX;

public:

	std::vector<TerrainVertex> RawVertacies;				//Very Uniform, Never used in the GPU.
	std::vector<TransformedVertex> TransformedVerticies;    //Can Change, Used in the GPU.

	TerrainMesh();
	~TerrainMesh();

	void Deload();
	void Upload();
};