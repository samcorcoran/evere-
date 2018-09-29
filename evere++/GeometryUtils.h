#ifndef GEOMETRYUTILS_H
#define GEOMETRYUTILS_H

#include <memory>
#include <vector>
#include <map>

#include "Point.h"
#include "Triangle.h"

namespace GeometryUtils {

	std::size_t get_t_point_hash(const Point* const p1, const Point* const p2, const float t);

	void subdivide_triangle_into_four(const Triangle&  triangle, std::vector<std::unique_ptr<Triangle>>& new_triangles, std::map<std::size_t, std::shared_ptr<Point>> &known_subdivision_points);

	void subdivide_triangles(std::vector<std::unique_ptr<Triangle>>& triangles, const int subdivisions);

	void print_triangles(const std::vector<std::unique_ptr<Triangle>>& triangles);

	void create_octahedron_triangles(std::vector<std::unique_ptr<Triangle>>& triangles);

	float degrees(const float radians);

	float radians(const float degrees);

	float initial_bearing(const Point& p1, const Point& p2);

	float total_unique_triangle_points(const std::vector<std::unique_ptr<Triangle>>& triangles);
}

#endif