/*
    3-3. Write a bool function that is passed an array and the number of elements in
    that array and determines whether the data in the array is sorted. This should
    require only one pass!
*/

#include <iostream>
#include <string>
#include <algorithm>
using std::cout;
using std::cin;
using std::string;

bool isSorted(int intArray[], const int ARRAY_SIZE)
{
    for (int i = 0; i < ARRAY_SIZE - 1; i++)
    {
        if (intArray[i] > intArray[i + 1])
            return false;
    }

    return true;
}

int compare(const void* voidA, const void* voidB)
{
    int* intA = (int*)(voidA);
    int* intB = (int*)(voidB);

    return *intA - *intB;
}

int main() {
    const int ARRAY_SIZE = 12;
    int intArray[ARRAY_SIZE] = {1856, 498, 30924, 87478, 328, 2653, 387, 3754, 387587, 2873, 276, 32};

    if (isSorted(intArray, ARRAY_SIZE))
        cout << "The array is sorted!\n";
    else
        cout << "The array isn't sorted!\n";

    qsort(intArray, ARRAY_SIZE, sizeof(int), compare);

    if (isSorted(intArray, ARRAY_SIZE))
        cout << "The array is sorted!\n";
    else
        cout << "The array isn't sorted!\n";
    
    return 0;
}