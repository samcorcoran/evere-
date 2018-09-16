#ifndef GEOMETRYUTILS_H
#define GEOMETRYUTILS_H

#include "Triangle.h"
#include "Point.h"
#include <chrono>

size_t get_t_point_hash(const shared_ptr<Point>& p1, const shared_ptr<Point>& p2, float t)
{
	std::size_t seed = 0;
	hash_combine(seed, p1);
	hash_combine(seed, p2);
	hash_combine(seed, t);

	return seed;
}

void subdivide_triangle_into_four(unique_ptr<Triangle> const &triangle, vector<unique_ptr<Triangle>>& new_triangles, map<size_t, shared_ptr<Point>> &known_subdivision_points)
{
	shared_ptr<Point> p4;
	size_t p4_hash = get_t_point_hash(triangle->p1, triangle->p2, 0.5f);
	auto it = known_subdivision_points.find(p4_hash);
	if (it != known_subdivision_points.end())
	{
		p4 = it->second;
	}
	else
	{
		p4 = make_shared<Point>(triangle->p1, triangle->p2, 0.5f);
		known_subdivision_points[p4_hash] = p4;
		// Hash of the points the other way round
		size_t p4_hash_alternative = get_t_point_hash(triangle->p2, triangle->p1, 0.5f);
		known_subdivision_points[p4_hash_alternative] = p4;
	}

	shared_ptr<Point> p5;
	size_t p5_hash = get_t_point_hash(triangle->p1, triangle->p3, 0.5f);
	it = known_subdivision_points.find(p5_hash);
	if (it != known_subdivision_points.end())
	{
		p5 = it->second;
	}
	else
	{
		p5 = make_shared<Point>(triangle->p1, triangle->p3, 0.5f);
		known_subdivision_points[p5_hash] = p5;
		// Hash of the points the other way round
		size_t p5_hash_alternative = get_t_point_hash(triangle->p3, triangle->p1, 0.5f);
		known_subdivision_points[p5_hash_alternative] = p5;
	}

	shared_ptr<Point> p6;
	size_t p6_hash = get_t_point_hash(triangle->p1, triangle->p3, 0.5f);
	it = known_subdivision_points.find(p6_hash);
	if (it != known_subdivision_points.end())
	{
		p6 = it->second;
	}
	else
	{
		p6 = make_shared<Point>(triangle->p2, triangle->p3, 0.5f);
		known_subdivision_points[p6_hash] = p6;
		// Hash of the points the other way round
		size_t p6_hash_alternative = get_t_point_hash(triangle->p3, triangle->p2, 0.5f);
		known_subdivision_points[p6_hash_alternative] = p6;
	}

	new_triangles.push_back(make_unique<Triangle>(triangle->p1, p4, p5));
	new_triangles.push_back(make_unique<Triangle>(p5, p6, triangle->p3));
	new_triangles.push_back(make_unique<Triangle>(p5, p4, p6));
	new_triangles.push_back(make_unique<Triangle>(p4, triangle->p2, p6));
}

void subdivide_triangles(vector<unique_ptr<Triangle>>& triangles, int subdivisions)
{
	// Track function duration
	std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();

	cout << "Subdividing triangles " << subdivisions << " times." << '\n';
	vector < unique_ptr<Triangle>> new_triangles;
	for (auto i = 0; i < subdivisions; ++i)
	{
		cout << "Subdivision " << i+1 << "... (operating on " << triangles.size() << " triangles)" << '\n';
		map<size_t, shared_ptr<Point>> known_subdivision_points;
		for (auto const& next_triangle : triangles)
		{
			subdivide_triangle_into_four(next_triangle, new_triangles, known_subdivision_points);
		}
		std::swap(triangles, new_triangles);
		new_triangles.clear();
	}
	cout << "After subdivision total triangles: " << triangles.size() << '\n';

	// Print function duration
	std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
	auto duration_s = std::chrono::duration_cast<std::chrono::seconds>(t2 - t1).count();
	auto duration_ms = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
	cout << "Subdivision took: " << duration_s << "s (or " << duration_ms << "ms)\n";
}

void print_triangles(vector<unique_ptr<Triangle>>& triangles)
{
	cout << "Printing triangles... \nTotal triangles: " << std::to_string(triangles.size()) << '\n';
	for (auto const& next_triangle : triangles)
	{
		next_triangle->print();
	}
	cout << "End of triangles";
}

void create_octahedron_triangles(vector<unique_ptr<Triangle>>& triangles) {
	shared_ptr<Point> p1 = make_shared<Point>(0.0f, 1.0f, 0.0f);
	shared_ptr<Point> p2 = make_shared<Point>(-1.0f, 0.0f, 0.0f);
	shared_ptr<Point> p3 = make_shared<Point>(0.0f, 0.0f, 1.0f);
	shared_ptr<Point> p4 = make_shared<Point>(1.0f, 0.0f, 0.0f);
	shared_ptr<Point> p5 = make_shared<Point>(0.0f, 0.0f, -1.0f);
	shared_ptr<Point> p6 = make_shared<Point>(0.0f, -1.0f, 0.0f);

	triangles.push_back(make_unique<Triangle>(p1, p2, p3));
	triangles.push_back(make_unique<Triangle>(p1, p3, p4));
	triangles.push_back(make_unique<Triangle>(p1, p4, p5));
	triangles.push_back(make_unique<Triangle>(p1, p5, p2));
	triangles.push_back(make_unique<Triangle>(p2, p5, p6));
	triangles.push_back(make_unique<Triangle>(p5, p4, p6));
	triangles.push_back(make_unique<Triangle>(p4, p3, p6));
	triangles.push_back(make_unique<Triangle>(p3, p2, p6));
}

float radians_to_degrees(float r) {
	return r * (180.0 / 3.141592653589793238463);
}

#endif