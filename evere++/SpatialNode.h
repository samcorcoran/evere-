#pragma once
#include "Point.h"

class SpatialNode
{
	SpatialNode(shared_ptr<Point> p);

public:
private:
	shared_ptr<Point> location;
};