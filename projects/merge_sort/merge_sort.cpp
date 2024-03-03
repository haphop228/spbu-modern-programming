#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

using namespace std;

const long long INF = 1e9;

void get_rand_vec(vector<int>& out, int size, int max_el_size) {  // создание случайного вектора
    mt19937 mt(time(NULL));
    
    for (int i = 0; i < size; i++)
        out.push_back(mt() % max_el_size);
}

void merge(vector<int>& vec, int l, int mid, int r) {
    int vec1_size, vec2_size;
    vec1_size = mid - l + 1;
    vec2_size = r - mid;

    vector<int> vec_first(vec1_size + 1); // вектор для левой части          
    vector<int> vec_second(vec2_size + 1); // вектор для правой части
   
    vec_first[vec1_size] = INF;  // последние элементы самый МАКС
    vec_second[vec2_size] = INF;

    for (int i = 0; i < vec1_size; i++) // заполняем первую часть
        vec_first[i] = vec[l + i];


    for (int i = 0; i < vec2_size; i++) // заполняем вторую часть
        vec_second[i] = vec[mid + i + 1];

    int k = l; // счётчики 
    int i = 0;
    int j = 0; 
    
    while (i < vec1_size and j < vec2_size) {
        if (vec_first[i] < vec_second[j]) {
            vec[k] = vec_first[i];
            i++;
        }
        else {
            vec[k] = vec_second[j];
            j++;
        }
        k++;
    }
    while (i < vec1_size) {
        vec[k] = vec_first[i];
        i++;
        k++;
    }
    while (j < vec2_size) {
        vec[k] = vec_second[j];
        j++;
        k++;
    }
}

void merge_sort(vector<int>& vec, int l, int r) {
    if (l < r) {
        int mid = (l + r) / 2;
        merge_sort(vec, l, mid);
        merge_sort(vec, mid + 1, r);
        merge(vec, l, mid, r);
    }
}

bool test(int n) {
    for (int i = 0; i < n; i++) {
        vector<int> a;
        get_rand_vec(a, 100, 10e4);
        vector<int> b = a;
        sort(b.begin(), b.end());
        merge_sort(a, 0, a.size() - 1);
        if (a != b)
            return 0;
    }
    return 1;
}

int main() {
    int n = 100;

    if (test(n))
        cout << "OK";
    else 
        cout << "Not OK";
}