#include <memory>
#include <vector>
#include <iostream>

#include "World.h"
#include "Triangle.h"
#include "GeometryUtils.h"
#include <chrono>

using namespace std;

World::World(int const subdivisions) {
	vector<unique_ptr<Triangle>> triangles;
	GeometryUtils::create_octahedron_triangles(triangles);
	GeometryUtils::subdivide_triangles(triangles, subdivisions);
	cout << endl << "Total triangles generated: " << triangles.size() << endl;

	//GeometryUtils::print_triangles(triangles);

	chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
	construct_nodes(triangles);
	chrono::high_resolution_clock::time_point t2 = chrono::high_resolution_clock::now();
	auto duration_s = chrono::duration_cast<chrono::seconds>(t2 - t1).count();
	auto duration_ms = chrono::duration_cast<chrono::milliseconds>(t2 - t1).count();
	cout << "Nodegraph construction took: " << duration_s << "s (or " << duration_ms << "ms)\n";
};

void World::construct_nodes(vector<unique_ptr<Triangle>> const & triangles) {

	map<Point const * const, SpatialCell * const> known_cells;
	map<Triangle const * const, SpatialNode * const> known_nodes;

	for (auto& t : triangles) {
		// TODO: Finish nodegraph creation

		// Each triangle-point represents a cell centre
		shared_ptr<SpatialCell> cell_one = retrieve_or_create_cell(known_cells, t->p1);
		shared_ptr<SpatialCell> cell_two = retrieve_or_create_cell(known_cells, t->p2);
		shared_ptr<SpatialCell> cell_three = retrieve_or_create_cell(known_cells, t->p3);

		// Each triangle-centre is a boundary point
		shared_ptr<SpatialNode> node = retrieve_or_create_node(known_nodes, t.get());

		// Cells must know about this perimeter node
		cell_one->add_perimeter_node(node);
		cell_two->add_perimeter_node(node);
		cell_three->add_perimeter_node(node);

		// Node must know about cells that surround it
		node->add_surrounding_cell(cell_one);
		node->add_surrounding_cell(cell_two);
		node->add_surrounding_cell(cell_three);

		// Cells must know about each other as neighbours
		cell_one->add_neighbour_cell(cell_two);
		cell_one->add_neighbour_cell(cell_three);
		cell_two->add_neighbour_cell(cell_one);
		cell_two->add_neighbour_cell(cell_three);
		cell_three->add_neighbour_cell(cell_one);
		cell_three->add_neighbour_cell(cell_two);
	}

	// Nodes must know about each other as neighbours
	for (auto& cell : known_cells) {
		// Sort their perimeter points by bearing, adding consecutive nodes as connections
		cell.second->sort_and_connect_perimeter_nodes();
		// Additionally, sort neighbouring cells
		cell.second->sort_neighbours_by_bearing();
	}

	// All nodes have full set of connected_nodes now, so sort
	for (auto& node : known_nodes) {
		node.second->sort_connected_nodes_by_bearing();
		node.second->sort_surrounding_cells_by_bearing();
	}

	// TODO: Calculate and store neighbour node/cell distances and/or proportions during above process
};

shared_ptr<SpatialCell> World::retrieve_or_create_cell(map<Point const * const, SpatialCell * const>& known_cells, shared_ptr<Point> p) {
	auto it = known_cells.find(p.get());
	if (it == known_cells.end()) {
		// Cell doesn't already exist
		return make_shared<SpatialCell>(p);
	}
	else {
		return shared_ptr<SpatialCell>{ it->second };
	}
};

shared_ptr<SpatialNode> World::retrieve_or_create_node(map<Triangle const * const, SpatialNode * const>& known_nodes, Triangle const * const t) {
	auto it = known_nodes.find(t);
	if (it == known_nodes.end()) {
		// Node doesn't already exist
		return make_shared<SpatialNode>(t->create_centre_point());
	}
	else {
		return shared_ptr<SpatialNode>{ it->second };
	}
};
