#ifndef SPATIALNODE_H
#define SPATIALNODE_H

#include <memory>

#include "Point.h"

class SpatialNode
{
	SpatialNode(std::shared_ptr<Point> p);

public:
private:
	std::shared_ptr<Point> location;
};

#endif