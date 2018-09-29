#ifndef WORLD_H
#define WORLD_H

#include <vector>
#include <memory>
#include <map>

#include "Triangle.h"
#include "SpatialNode.h"

class World {
public:
	World(const int subdivisions);
	std::vector<std::unique_ptr<SpatialNode>> nodes;
private:
	void construct_nodes(const std::vector<std::unique_ptr<Triangle>>& triangles);

	std::shared_ptr<SpatialCell> retrieve_or_create_cell(std::map<std::shared_ptr<Point>, std::shared_ptr<SpatialCell>>& known_cells, std::shared_ptr<Point> p);
};

#endif // WORLD_H