#ifndef SPATIALNODE_H
#define SPATIALNODE_H

#include <memory>
#include <set>

#include "Point.h"
#include "SpatialCell.h"

class SpatialNode
{
	SpatialNode(std::shared_ptr<Point> p);

public:
	std::set<std::shared_ptr<Point>> connected_nodes;
	std::set<std::shared_ptr<SpatialCell>> connected_cells;
	std::shared_ptr<Point> location;
private:
};

#endif