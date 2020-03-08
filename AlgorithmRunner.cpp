#include "AlgorithmRunner.h"

#define SQUARE_MAX 1005

AlgorithmRunner::AlgorithmRunner(std::list<Line*> l): lines(l){}

int64_t AlgorithmRunner::solve() {
	if (lines.size() < SQUARE_MAX) {
		auto intersection = n_square_solution();
		return intersection->size();
	}
	else {
		auto intersection = n_logn_solution();
		return intersection->size();
	}
}

/*
 * Vanilla solution.
*/
std::set<Point*, point_set_cmp>* AlgorithmRunner::n_square_solution() {
	auto inters = new std::set<Point*, point_set_cmp>();
	auto line_itr = this->lines.begin();
	for (auto itr1 = lines.begin(); itr1 != lines.end(); itr1++) {
		for (auto itr2 = itr1; itr2 != lines.end(); itr2++) {
			auto inter = Line::get_intersection((*itr1), (*itr2));
			if (inter != NULL) {
				inters->insert(inter);
			}
		}
	}
	return inters;
}

/*
 * optimized solution: scan algorithm.
*/
std::set<Point*, point_set_cmp>* AlgorithmRunner::n_logn_solution() {
	return NULL;
}