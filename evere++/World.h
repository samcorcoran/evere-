#ifndef WORLD_H
#define WORLD_H

#include <vector>
#include <memory>
#include <map>

#include "Triangle.h"
#include "SpatialNode.h"

class World {
public:
	World(int const subdivisions);
	std::vector<std::unique_ptr<SpatialNode>> nodes;
private:
	void construct_nodes(std::vector<std::unique_ptr<Triangle>> const & triangles);

	std::shared_ptr<SpatialCell> retrieve_or_create_cell(std::map<Point const * const, SpatialCell * const>& known_cells, std::shared_ptr<Point> p);
	std::shared_ptr<SpatialNode> retrieve_or_create_node(std::map<Triangle const * const, SpatialNode * const>& known_nodes, Triangle const * const t);
};

#endif // WORLD_H