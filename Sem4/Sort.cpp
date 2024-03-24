#include "Sort.h"
#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstdarg>

using namespace std;

Sort::Sort() {}

Sort::Sort(int n, int min, int max) {
    for (int i = 1; i <= n; i++)
        elements.push_back(rand() % (max - min + 1) + min);
}

Sort::Sort(initializer_list<int> initList) : elements(initList) {}

Sort::Sort(const vector<int> &v, int n) {
    elements.reserve(n);
    for (int i = 1; i <= n; i++)
        elements.push_back(v[i]);
}

Sort::Sort(int count, ...) {
    va_list args;
    va_start(args, count);
    for (int i = 1; i <= count; i++)
        elements.push_back(va_arg(args, int));
    va_end(args);
}

Sort::Sort(const string &str) {
    stringstream ss(str);
    int x;
    char caracter;
    while (ss >> x) {
        elements.push_back(x);
        ss >> caracter;
    }
}

void Sort::InsertSort(bool ascending = false) {
    int n = elements.size();
    for (int i = 1; i < n; i++) {
        int k = elements[i];
        int j = i - 1;
        if (ascending) {
            while (j >= 0 && elements[j] > k) {
                elements[j + 1] = elements[j];
                --j;
            }
        } else {
            while (j >= 0 && elements[j] < k) {
                elements[j + 1] = elements[j];
                --j;
            }
        }
        elements[j + 1] = k;
    }
}

void Sort::QuickSort(bool ascending = false) {
    quickSort(0, elements.size() - 1, ascending);
}

void Sort::quickSort(int left, int right, bool ascending) {
    if (left < right) {
        int pivotIndex = part(left, right, ascending);
        quickSort(left, pivotIndex - 1, ascending);
        quickSort(pivotIndex + 1, right, ascending);
    }
}

int Sort::part(int left, int right, bool ascending) {
    int pivot = elements[right];
    int i = left - 1;

    for (int j = left; j < right; ++j) {
        if ((ascending && elements[j] <= pivot) || (!ascending && elements[j] >= pivot)) {
            ++i;
            swap(elements[i], elements[j]);
        }
    }
    swap(elements[i + 1], elements[right]);
    return i + 1;
}

void Sort::BubbleSort(bool ascending = false) {
    int n = elements.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if ((!ascending && elements[j] < elements[j + 1]) ||
                (ascending && elements[j] > elements[j + 1])) {
                swap(elements[j], elements[j + 1]);
            }
        }
    }
}

void Sort::Print() const {
    for (int element : elements) {
        cout << element << " ";
    }
    cout << '\n';
}

int Sort::GetElementsCount() const {
    return elements.size();
}

int Sort::GetElementFromIndex(int index) const {
    if (index < 0 || index >= elements.size())
        return -1;
    return elements[index];
}
