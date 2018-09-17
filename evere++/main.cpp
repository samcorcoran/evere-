#include <iostream>
#include <string>

#include "World.h"

using namespace std;

int main(int argc, char* argv[])
{
	cout << "Generating node graph." << '\n';

	int subdivisions = 0;
	if (argc > 1)
	{
		subdivisions = std::stoi(argv[1]);
	}

	auto world = make_unique<World>(subdivisions);

	return 0;
}
