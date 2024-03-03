#ifndef MERGE_SORT_HPP
#define MERGE_SORT_HPP

#include <vector>
#include <algorithm>

namespace MergeNameSpace {
	void merge(std::vector<long long>& vec, int l, int mid, int r);
	void merge_sort(std::vector<long long>& vec, int l, int r);
}

#endif