#include <memory>
#include <vector>
#include <utility>	// std::pair
#include <algorithm>	// std::sort

#include "SpatialCell.h"
#include "Point.h"
#include "GeometryUtils.h"

using namespace std;

SpatialCell::SpatialCell(std::shared_ptr<Point> centre) : centre(centre) {
};

void SpatialCell::add_perimeter_node(std::shared_ptr<SpatialNode> n) {
	perimeter.emplace(n);
};

void SpatialCell::add_neighbour_cell(std::shared_ptr<SpatialCell> c) {
	neighbours.emplace(c);
}

void SpatialCell::sort_perimeter_by_bearing() {
	// Calculate bearings to each perimeter node
	auto perimeter_bearings = vector<pair<shared_ptr<SpatialNode>, float>>();
	for (auto& node : perimeter) {
		perimeter_bearings.emplace_back(make_pair(node,
								GeometryUtils::initial_bearing(*centre, *node->location)));
	}
	// Sort pairs based on bearing values
	sort(perimeter_bearings.begin(), perimeter_bearings.end(), [](auto &left, auto &right) {
		return left.second < right.second;
	});
	// Update perimeter with new ordering
	perimeter.clear();
	for (auto& p : perimeter_bearings) {
		perimeter.emplace(p.first);
	}
}

void SpatialCell::sort_neighbours_by_bearing() {
	// Calculate bearings to each neighbouring cell
	vector<pair<shared_ptr<SpatialCell>, float>> neighbour_bearings(neighbours.size());
	for (auto& cell : neighbours) {
		neighbour_bearings.emplace_back(make_pair(cell,
			GeometryUtils::initial_bearing(*centre, *cell->centre)));
	}
	// Sort pairs based on bearing values
	sort(neighbour_bearings.begin(), neighbour_bearings.end(), [](auto &left, auto &right) {
		return left.second < right.second;
	});
	// Update neighbours set with new ordering
	neighbours.clear();
	for (auto& p : neighbour_bearings) {
		neighbours.emplace(p.first);
	}
}

void SpatialCell::sort_and_connect_perimeter_nodes()
{
	// Sort nodes into ring
	sort_perimeter_by_bearing();
	// Early return for single node "ring"
	if (perimeter.size() <= 1) {
		return;
	}
	// Connect consecutive nodes in ring
	for (auto it = perimeter.begin(); it != perimeter.end(); ++it) {
		if (next(it) != perimeter.end()) {
			// Add bi-directional connection
			(*it)->add_connected_node(*next(it));
			(*next(it))->add_connected_node((*it));
		}
	}
	// Connect first and last in ring
	shared_ptr<SpatialNode> last_node = *perimeter.rbegin();
	shared_ptr<SpatialNode> first_node = *perimeter.begin();
	first_node->add_connected_node(last_node);
	last_node->add_connected_node(first_node);
}
