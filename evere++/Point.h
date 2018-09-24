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
	Point(float const x, float const y, float const z);

	Point(Point const & p1, Point const & p2, float const t);

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
