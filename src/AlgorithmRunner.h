#pragma once

#include<iostream>
#include<set>
#include<vector>
#include<queue>
#include<list>

#include "Line.h"
#include "Point.h"
#include "Rational.h"

class AlgorithmRunner
{
private:
	std::list<Line*>* lines;
	// strategy 1: N^2 algorithm
	// std::set<Point*> intersection;

	// strategy 2: NlogN algorithm
	// std::priority_queue<Point*, std::vector<Point*>, cmp_by_y> y_sort;

public:
	AlgorithmRunner(std::list<Line*>*);
	int64_t solve();
	std::set<Point*, point_set_cmp>* n_square_solution();
	std::set<Point*, point_set_cmp>* n_logn_solution();
};

/*
struct cmp_by_y {
	bool operator() (Point* a, Point* b) {
		if (b->get_y() < a->get_y()) {
			return true;
		}
		else {
			return false;
		}
	}
};
*/