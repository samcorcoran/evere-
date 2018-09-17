#ifndef WORLD_H
#define WORLD_H

#include <vector>
#include <memory>

#include "Triangle.h"
#include "SpatialNode.h"

class World {
public:
	World(int const subdivisions);
	std::vector<std::unique_ptr<SpatialNode>> nodes;
private:
	void construct_nodes(std::vector<std::unique_ptr<Triangle>> const & triangles);
};

#endif // WORLD_H