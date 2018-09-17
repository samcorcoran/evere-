#include <memory>
#include <vector>

#include "SpatialCell.h"
#include "Point.h"

using namespace std;

SpatialCell::SpatialCell(std::shared_ptr<Point> centre) : centre(centre) {
};

void SpatialCell::add_perimeter_point(std::shared_ptr<Point> p) {
	perimeter.emplace(p);
};