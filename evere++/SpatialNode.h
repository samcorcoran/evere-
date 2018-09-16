#ifndef SPATIALNODE_H
#define SPATIALNODE_H

#include "Point.h"

class SpatialNode
{
	SpatialNode(shared_ptr<Point> p);

public:
private:
	shared_ptr<Point> location;
};

#endif