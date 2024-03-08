#include "NumberList.h"
#include <iostream>
#include <algorithm>

NumberList::NumberList() : numbers(nullptr), count(0), capacity(0) {}

NumberList::~NumberList()
{
    delete[] numbers; // Deallocate memory
}

void NumberList::Init()
{
    count = 0;
}

bool NumberList::Add(int x)
{
    if (count >= capacity)
    {
        // Double the capacity if full
        int newCapacity = (capacity == 0) ? 1 : 2 * capacity;
        int *newNumbers = new int[newCapacity];

        if (!newNumbers)
            return false; // Memory allocation failed

        // Copy existing elements
        for (int i = 0; i < count; ++i)
            newNumbers[i] = numbers[i];

        // Deallocate old memory
        delete[] numbers;

        // Update pointer and capacity
        numbers = newNumbers;
        capacity = newCapacity;
    }

    // Add new element
    numbers[count++] = x;
    return true;
}

void NumberList::Sort()
{
    std::sort(numbers, numbers + count);
}

void NumberList::Print()
{
    for (int i = 0; i < count; ++i)
        std::cout << numbers[i] << " ";
    std::cout << std::endl;
}
