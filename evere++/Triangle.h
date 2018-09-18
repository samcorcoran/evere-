#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <memory>
#include "Point.h"

class Triangle
{
public:
	int id;
	std::shared_ptr<Point> p1;
	std::shared_ptr<Point> p2;
	std::shared_ptr<Point> p3;

	Triangle(std::shared_ptr<Point> p1, std::shared_ptr<Point>p2, std::shared_ptr<Point>p3);

	std::shared_ptr<Point> create_centre_point() const;

	void print();
private:
	static size_t triangle_counter;
};

#endif