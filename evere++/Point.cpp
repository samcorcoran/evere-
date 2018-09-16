#include "Point.h"
#include <iostream>
#include <memory>
#include "GeometryUtils.h"

using namespace std;

size_t Point::point_counter = 1;

Point::Point(float const x, float const y, float const z) : x(x), y(y), z(z), id(point_counter) {

	increment_counter();
}

Point::Point(Point const & p1, Point const & p2, float const t) {
	x = p1.x + (p2.x - p1.x) * t;
	y = p1.y + (p2.y - p1.y) * t;
	z = p1.z + (p2.z - p1.z) * t;
	normalize();
	increment_counter();
}

string Point::to_string() {
	return std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z);
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

void Point::set_geographic_location()
{
}