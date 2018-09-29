#ifndef POINT_H
#define POINT_H

#include <string>

struct GeographicLocation {
	float longitude;
	float latitude;

	GeographicLocation(float longitude, float latitude) : longitude{ longitude }, latitude{ latitude } {
	}
};

class Point
{
public:
	Point(const float x, const float y, const float z);

	Point(const Point& p1, const Point& p2, const float t);

	std::string to_string();

	int id;
	float x;
	float y;
	float z;

	std::unique_ptr<GeographicLocation> geographic_location;

private:
	void initialize_point();

	void increment_counter();

	float magnitude();

	void normalize();

	void calculate_geographic_location();

	static std::size_t point_counter;

};

#endif
