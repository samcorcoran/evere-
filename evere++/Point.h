#pragma once
#include <math.h>
#include <memory>
#include <string>

using namespace std;

class Point
{
public:
	int id;
	float x;
	float y;
	float z;

	Point(float x, float y, float z);

	Point(const std::shared_ptr<Point> & p1, const std::shared_ptr<Point> & p2, float t);

	void increment_counter();

	float magnitude();

	void normalize();

	string to_string();

private:
	static size_t point_counter;
};
