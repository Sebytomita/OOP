#include "Sort.h"
#include <iostream>

using namespace std;

int main() {
    
    Sort v1(10, 1, 100); // Random list
    v1.Print();
    
    Sort v2 = {5, 1, 7, 2, 3}; // Init list
    v2.Print();

    vector<int> vec = {10, 7, 25, 2, 46};
    Sort v3(vec, 3); // First x elements
    v3.Print();

    Sort v4(6, 21, 41, 61, 81, 11, 52); // Variadic list
    v4.Print();

    Sort v5("10,40,100,5,70"); // string list
    v5.Print();

    v2.InsertSort(); 
    v2.Print();

    v3.BubbleSort(true); 
    v3.Print();

    v4.QuickSort();
    v4.Print();

    cout << "Nr elemente v5: " << v5.GetElementsCount() << '\n';
    cout << "Elemente de la 3 incolo: " << v5.GetElementFromIndex(3) << '\n';

    return 0;
}
