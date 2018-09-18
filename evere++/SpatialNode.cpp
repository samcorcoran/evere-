#include <memory>
#include <vector>
#include <utility>	// std::pair
#include <algorithm>	// std::sort

#include "SpatialNode.h"
#include "SpatialCell.h"
#include "GeometryUtils.h"

using namespace std;

SpatialNode::SpatialNode(std::shared_ptr<Point> p) : location(p) {
}

void SpatialNode::add_surrounding_cell(shared_ptr<SpatialCell> cell) {
	surrounding_cells.emplace(cell);
}

void SpatialNode::add_connected_node(shared_ptr<SpatialNode> node) {
	connected_nodes.emplace(node);
}

void SpatialNode::sort_connected_nodes_by_bearing() {
	// Calculate bearings to each connected node
	vector<pair<shared_ptr<SpatialNode>, float>> node_bearings(connected_nodes.size());
	for (auto& node : connected_nodes) {
		node_bearings.emplace_back(make_pair(node,
			GeometryUtils::initial_bearing(*location, *node->location)));
	}
	// Sort pairs based on bearing values
	sort(node_bearings.begin(), node_bearings.end(), [](auto &left, auto &right) {
		return left.second < right.second;
	});
	// Update connected nodes with new ordering
	connected_nodes.clear();
	for (auto& p : node_bearings) {
		connected_nodes.emplace(p.first);
	}
}

void SpatialNode::sort_surrounding_cells_by_bearing() {
	// Calculate bearings to each surrounding cell
	vector<pair<shared_ptr<SpatialCell>, float>> neighbour_bearings(surrounding_cells.size());
	for (auto& cell : surrounding_cells) {
		neighbour_bearings.emplace_back(make_pair(cell,
			GeometryUtils::initial_bearing(*location, *cell->centre)));
	}
	// Sort pairs based on bearing values
	sort(neighbour_bearings.begin(), neighbour_bearings.end(), [](auto &left, auto &right) {
		return left.second < right.second;
	});
	// Update surrounding cells set with new ordering
	surrounding_cells.clear();
	for (auto& p : neighbour_bearings) {
		surrounding_cells.emplace(p.first);
	}
}