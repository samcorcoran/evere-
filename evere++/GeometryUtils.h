#ifndef GEOMETRYUTILS_H
#define GEOMETRYUTILS_H

#include <memory>
#include <vector>
#include <map>

#include "Point.h"
#include "Triangle.h"

namespace GeometryUtils {

	std::size_t get_t_point_hash(Point const * const p1, Point const * const p2, float const t);

	void subdivide_triangle_into_four(Triangle const &  triangle, std::vector<std::unique_ptr<Triangle>>& new_triangles, std::map<std::size_t, std::shared_ptr<Point>> &known_subdivision_points);

	void subdivide_triangles(std::vector<std::unique_ptr<Triangle>>& triangles, int const subdivisions);

	void print_triangles(std::vector<std::unique_ptr<Triangle>> const & triangles);

	void create_octahedron_triangles(std::vector<std::unique_ptr<Triangle>>& triangles);

	float radians_to_degrees(float const r);
}

#endif