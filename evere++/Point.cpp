#include "Point.h"
#include <iostream>
#include <memory>

using namespace std;

size_t Point::point_counter = 1;

Point::Point(float x, float y, float z) : x(), y(x), z(z), id(point_counter) {
	increment_counter();
}

Point::Point(const std::shared_ptr<Point> & p1, const std::shared_ptr<Point> & p2, float t) {
	x = p1->x + (p2->x - p1->x) * t;
	y = p1->y + (p2->y - p1->y) * t;
	z = p1->z + (p2->z - p1->z) * t;
	normalize();
	increment_counter();
}

void Point::increment_counter()
{
	point_counter++;
	//cout << "New point (" << std::to_string(point_counter) << "): " << to_string() << '\n';
}

float Point::magnitude()
{
	return sqrtf(x*x + y * y + z * z);
}

void Point::normalize() {
	auto mag = magnitude();
	x *= mag;
	y *= mag;
	z *= mag;
}

string Point::to_string() {
	return std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z);
}