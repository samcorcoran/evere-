#include <memory>
#include <vector>
#include <iostream>

#include "World.h"
#include "Triangle.h"
#include "GeometryUtils.h"

using namespace std;

World::World(int const subdivisions) {
	vector<unique_ptr<Triangle>> triangles;
	GeometryUtils::create_octahedron_triangles(triangles);
	GeometryUtils::subdivide_triangles(triangles, subdivisions);
	cout << "\nTotal triangles generated: " << triangles.size();
	//print_triangles(triangles);

	construct_nodes(triangles);
};

void World::construct_nodes(vector<unique_ptr<Triangle>> const & triangles) {
	for (auto& t : triangles)
	{
		// TODO:
		// Create cell from each point
		// Create spatial node from triangle centre
		// Add node to perimeter of each cell
		// Add cell to 'converging' list for each node
	}
};
