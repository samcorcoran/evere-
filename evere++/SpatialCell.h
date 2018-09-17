#ifndef SPATIALCELL_H
#define SPATIALCELL_H

#include <memory>
#include <set>

#include "Point.h"

class SpatialCell {
public:
	SpatialCell(std::shared_ptr<Point> p);

	std::shared_ptr<Point> centre;
	std::set<std::shared_ptr<Point>> perimeter;

	void add_perimeter_point(std::shared_ptr<Point> p);
private:
};

#endif // SPATIALCELL_H