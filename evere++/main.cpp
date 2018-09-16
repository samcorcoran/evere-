#include <iostream>
#include <vector>
#include <memory>
#include <map>
#include "Triangle.h"
#include "GeometryUtils.h"

using namespace std;

int main(int argc, char* argv[])
{
	cout << "Generating node graph." << '\n';

	int subdivisions = 0;
	if (argc > 1)
	{
		subdivisions = std::stoi(argv[1]);
	}
	vector<unique_ptr<Triangle>> triangles;
	GeometryUtils::create_octahedron_triangles(triangles);
	GeometryUtils::subdivide_triangles(triangles, subdivisions);
	cout << "End of main, total triangles: " << triangles.size();
	//print_triangles(triangles);

	return 0;
}
