// Intersection.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <list>
#include <fstream>
#include "AlgorithmRunner.h"

int main(int argc, char* argv[])
{
	std::ifstream input;
	std::ofstream output;
	
	/*
	 * command line args parser is cited from https://github.com/RyanSunye/IntersectProject
	*/
	// ===== citation start =====
	for (int i = 0; i < argc; i++) {
		if (strncmp(argv[i], "-i", 2) == 0) {
			input = std::ifstream(argv[i + 1]);
		}
		else if (strncmp(argv[i], "-o", 2) == 0) {
			output = std::ofstream(argv[i + 1]);
		}
	}
	// =====  citation end  =====

	auto object_list = new std::list<Line*>;
	int N;
	// input objects number
	input >> N;
	for (int i = 0; i < N; i++) {
		char type;
		int64_t x1, y1, x2, y2;
		input >> type >> x1 >> y1 >> x2 >> y2;
		if (type == 'L') {
			auto p1 = new Point(new Rational(x1), new Rational(y1));
			auto p2 = new Point(new Rational(x2), new Rational(y2));
			auto line = new Line(p1, p2);
			object_list->push_back(line);
		}
		else {
			std::cerr << i << " unsupported geometry object, ignored.";
		}
	}
	// solve the problem
	auto solver = new AlgorithmRunner(object_list);
	output << solver->solve() << std::endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
