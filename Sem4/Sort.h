#ifndef SORT_H
#define SORT_H

#include <vector>
#include <initializer_list>
#include <string>

class Sort
{
private:
    std::vector<int> elements;

public:
    Sort();
    Sort(int n, int min, int max);
    Sort(std::initializer_list<int> initList);
    Sort(const std::vector<int> &v, int n);
    Sort(int count, ...);
    Sort(const std::string &str);
    
    void InsertSort(bool ascending = false);

    void QuickSort(bool ascending = false);
    void quickSort(int left, int right, bool ascending);
    int part(int left, int right, bool ascending);

    void BubbleSort(bool ascending = false);
    
    void Print() const;

    int GetElementsCount() const;
    int GetElementFromIndex(int index) const;
};

#endif
