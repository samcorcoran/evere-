#include "Triangle.h"
#include <iostream>
#include <memory>

size_t Triangle::triangle_counter = 1;

Triangle::Triangle(shared_ptr<Point> p1, shared_ptr<Point>p2, shared_ptr<Point>p3) : p1(p1), p2(p2), p3(p3), id(triangle_counter) {
	triangle_counter++;
	//cout << "New triangle (" << std::to_string(id) << "): " << p1->to_string() << ", " << p2->to_string() << ", " << p3->to_string() << '\n';
}

void Triangle::print() {
	cout << p1->to_string() + p2->to_string() + p3->to_string() << '\n';
}
