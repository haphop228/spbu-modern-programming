#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <unordered_set>
#include <algorithm>
#include <set>

using namespace std;

vector<int> rand_vec(int size) {
	
	vector<int> rand_vector(size);
	mt19937 mt(time(nullptr));
	
	for (int i = 0; i < size; i++) {
		rand_vector[i] = mt() % 10;
		//cout << rand_vector[i] << " ";
	}
	return rand_vector;
}


vector <int> shell_sort(vector <int> a, vector<int> v) {
	
	int h = v[v.size() - 1];
	int n = a.size();
	int k = v.size() - 1;
	
	for (; h > 0; h = v[k]) {
		for (int i = h; i < n; ++i) {
			//cout << i << ' ';
			int temp = a[i];
			int j = i;
			for (; j >= h && a[j - h] > temp; j -= h)
				a[j] = a[j - h];
			a[j] = temp;
		}
		if (k == 0)
			return a;
		else
			k--;
	}
}

void vec_out(vector<int> a) {
	for (int i = 0; i < a.size(); i++) {
		std::cout << a[i] << ' ';
	}
	cout << endl;
}

void smooth_nums(int num, int size, set<int>& set_nums) {
	if (num < size) {
		set_nums.insert(num);
		smooth_nums(num * 2, size, set_nums);
		smooth_nums(num * 3, size, set_nums);
	}
}

void time_comparer(int size) {
	cout << "Size of array: " << size << endl;
	vector<int> sorted;
	set<int> a;

	sorted = rand_vec(size);
	//sorted = { 2, 3, 5, 10, 2, 3, 15, 1, 6, 8, 3, 14, 9 };
	smooth_nums(1, size / 3, a);
	std::vector<int> v(a.begin(), a.end());

	unsigned int start_time = clock();
	vector<int> shell_sort_mas = shell_sort(sorted, v);
	unsigned int end_shell_begin_q = clock();

	cout << "Shell sort time: " << endl;
	cout << end_shell_begin_q - start_time << endl;
	
	sort(sorted.begin(), sorted.end());
	unsigned int end_of_sorting_time = clock();
	
	cout << "Quick sort time: " << endl;
	cout << end_of_sorting_time - end_shell_begin_q << " " << endl;
	cout << endl;
}

int main(){
	int size = 1e10;
	vector<double> sizes = { 1e3, 1e4, 1e5, 1e6 };

	for (int i = 0; i < sizes.size(); i++) {
		time_comparer(sizes[i]);
	}
}