#ifndef SPATIALCELL_H
#define SPATIALCELL_H

#include <memory>
#include <set>

#include "Point.h"
#include "SpatialNode.h"

class SpatialNode;

class SpatialCell {
public:
	SpatialCell(std::shared_ptr<Point> p);

	std::shared_ptr<Point> centre;
	std::set<std::shared_ptr<SpatialNode>> perimeter;
	std::set<std::shared_ptr<SpatialCell>> neighbours;

	void add_perimeter_node(std::shared_ptr<SpatialNode> n);
	void add_neighbour_cell(std::shared_ptr<SpatialCell> c);

	void sort_perimeter_by_bearing();
	void sort_neighbours_by_bearing();

	void sort_and_connect_perimeter_nodes();
private:
};

#endif // SPATIALCELL_H