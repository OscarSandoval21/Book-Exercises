/*
    3-2. Rewrite the code that finds the agent with the best monthly sales average so
    that it finds the agent with the highest median sales. As stated earlier, the median
    of a set of values is the “one in the middle,” such that half of the other values
    are higher and half of the other values are lower. If there is an even number
    of values, the median is the simple average of the two values in the middle.
    For example, in the set 10, 6, 2, 14, 7, 9, the values in the middle are 7 and 9.
    The average of 7 and 9 is 8, so 8 is the median.
*/

#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::string;

int compareMonthlySales(const void* voidA, const void* voidB)
{
    int* intA = (int*)(voidA);
    int* intB = (int*)(voidB);

    return (*intA - *intB);
}

void printSales(int sales[], const int NUM_MONTHS)
{
    for (int i = 0; i < NUM_MONTHS; i++)
        cout << sales[i] << ", ";
    cout << "\n";
}

float findHighestMedian(int sales[], const int NUM_MONTHS)
{
    if (NUM_MONTHS % 2 == 0)
    {
        int middle = NUM_MONTHS / 2;
        return (sales[middle] + sales[middle - 1]) / 2;
    }
    else
        return sales[NUM_MONTHS / 2];
}

int main() {
    const int NUM_AGENTS = 3;
    const int NUM_MONTHS = 12;
    int sales[NUM_AGENTS][NUM_MONTHS] = {
        {1856, 498, 30924, 87478, 328, 2653, 387, 3754, 387587, 2873, 276, 32},
        {5865, 5456, 3983, 6464, 9957, 4785, 3875, 3838, 4959, 1122, 7766, 2534},
        {23, 55, 67, 99, 265, 376, 232, 223, 4546, 564, 4544, 3434}
    };
    int highestMedian = 0;

    cout << "Before sorting:\n";
    for (int i = 0; i < NUM_AGENTS; i++)
    {
        printSales(sales[i], NUM_MONTHS);
        qsort(sales[i], NUM_MONTHS, sizeof(int), compareMonthlySales);
    }

    highestMedian = 0;

    cout << "\nAfter sorting:\n";
    for (int agent = 0; agent < NUM_AGENTS; agent++)
    {
        printSales(sales[agent], NUM_MONTHS);

        if (findHighestMedian(sales[agent], NUM_MONTHS) > findHighestMedian(sales[highestMedian], NUM_MONTHS))
            highestMedian = agent;
    }

    cout << "\nAgent #" << highestMedian + 1 << " has the highest median of " << findHighestMedian(sales[highestMedian], NUM_MONTHS) << "\n";

    
    return 0;
}
