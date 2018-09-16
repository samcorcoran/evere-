#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <math.h>
#include <memory>
#include <string>
#include "Point.h"

class Triangle
{
public:
	int id;
	std::shared_ptr<Point> p1;
	std::shared_ptr<Point> p2;
	std::shared_ptr<Point> p3;

	Triangle(std::shared_ptr<Point> p1, std::shared_ptr<Point>p2, std::shared_ptr<Point>p3);

	void print();
private:
	static size_t triangle_counter;
};

#endif