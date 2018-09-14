#pragma once
#include <math.h>
#include <memory>
#include <string>

using namespace std;

struct GeographicLocation {
	float longitude;
	float latitude;
};

class Point
{
public:
	Point(float x, float y, float z);

	Point(const std::shared_ptr<Point> & p1, const std::shared_ptr<Point> & p2, float t);

	string to_string();

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

	static size_t point_counter;

};
