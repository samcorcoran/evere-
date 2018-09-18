#ifndef SPATIALNODE_H
#define SPATIALNODE_H

#include <memory>
#include <set>

#include "Point.h"
#include "SpatialCell.h"

class SpatialCell;

class SpatialNode
{
public:
	std::set<std::shared_ptr<SpatialNode>> connected_nodes;
	std::set<std::shared_ptr<SpatialCell>> surrounding_cells;
	std::shared_ptr<Point> location;

	SpatialNode(std::shared_ptr<Point> p);

	void add_surrounding_cell(std::shared_ptr<SpatialCell> cell);
	void add_connected_node(std::shared_ptr<SpatialNode> node);

	void sort_connected_nodes_by_bearing();
	void sort_surrounding_cells_by_bearing();

private:
};

#endif