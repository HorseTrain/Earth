#pragma once

#include <vector>
#include "../glm/vec3.hpp"
#include "inttypes.h"

struct TerrainVertex
{
	glm::dvec3 Position;
	glm::dvec3 Normal;
};

class TerrainMesh
{
public:

	std::vector<TerrainVertex> VertexPositions;
	std::vector<uint16_t> VertexIndecies;
};