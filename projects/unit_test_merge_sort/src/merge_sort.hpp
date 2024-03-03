#ifndef MERGE_SORT_HPP
#define MERGE_SORT_HPP

#include <vector>
#include <algorithm>

namespace MergeNameSpace {
	void merge(std::vector<int>& vec, int l, int mid, int r);
	void merge_sort(std::vector<int>& vec, int l, int r);
}

#endif