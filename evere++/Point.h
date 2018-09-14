#pragma once
#include <math.h>
#include <memory>
#include <string>

using namespace std;

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


	void increment_counter();

	float magnitude();

	void normalize();


	static size_t point_counter;

};
