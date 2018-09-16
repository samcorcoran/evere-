#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <math.h>
#include <memory>
#include <string>
#include "Point.h"

using namespace std;

class Triangle
{
public:
	int id;
	shared_ptr<Point> p1;
	shared_ptr<Point> p2;
	shared_ptr<Point> p3;

	Triangle(shared_ptr<Point> p1, shared_ptr<Point>p2, shared_ptr<Point>p3);

	void print();
private:
	static size_t triangle_counter;
};

#endif