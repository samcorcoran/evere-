#ifndef POINT_H
#define POINT_H

#include <math.h>
#include <memory>
#include <string>

struct GeographicLocation {
	float longitude;
	float latitude;
};

class Point
{
public:
	Point(float const x, float const y, float const z);

	Point(Point const & p1, Point const & p2, float const t);

	std::string to_string();

private:
	int id;
	float x;
	float y;
	float z;

	GeographicLocation geographicLocation;

	void increment_counter();

	float magnitude();

	void normalize();

	void set_geographic_location();

	static std::size_t point_counter;

};

#endif
