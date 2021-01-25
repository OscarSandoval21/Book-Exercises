/*
    3-9. Consider this modification of the sales array: Because salespeople come and
    go throughout the year, we are now marking months prior to a sales agent’s
    hiring, or after a sales agent’s last month, with a –1. Rewrite your highest
    sales average, or highest sales median, code to compensate.
*/

/*
    Plan Outline:
    > If there are going to be -1 values in a salesperson's array, then they cannot
    be counted towards their average, or as part of their median, since having a
    -1 means that they were not yet working there or have already left.
    This means that only the numbers with actual values must count for them.
    > Once sorted, all of the -1 values will be sent to the beginning of the array,
    so I need to figure out a way to find how many -1 values there are in order to find
    the median of a salesperson.
    > For the average, it's only a matter of keeping a track of the -1 values and not
    including them in the total sum of that array. Once the sum of all values is complete,
    the number of -1 values can be used to subtract from the total and then divide the sum
    by the resulting value.

    Steps:
    > Rewrite the function for finding a salesperson's average so that it doesn't include the
    -1 values that they might have in their array.
    
*/


#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::string;

float findAverage(int sales[], const int NUM_MONTHS)
{
    float sum = 0;
    int monthsWorked = 0;

    for (int i = 0; i < NUM_MONTHS; i++)
    {
        if (sales[i] != -1)
        {
            sum += sales[i];
            monthsWorked++;
        }
    }

    return (sum / monthsWorked);
}

int findMedian(int sales[], const int NUM_MONTHS)
{
    int monthsWorked = 0;
    int median;

    for (int i = 0; i < NUM_MONTHS; i++)
    {
        if (sales[i] != -1)
            monthsWorked++;
    }

    median = monthsWorked / 2;
    median += NUM_MONTHS - monthsWorked;

    if (monthsWorked % 2 == 0)
        return (sales[median] + sales[median - 1]) / 2;
    else
        return sales[median];
    
}

int compareFunction(const void* voidA, const void* voidB)
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

int main() {
    const int NUM_AGENTS = 3;
    const int NUM_MONTHS = 12;
    int sales[NUM_AGENTS][NUM_MONTHS] = {
        {-1, -1, -1, 87478, 328, 2653, 387, 3754, 387587, 2873, 276, 32},
        {5865, 5456, 3983, 6464, 9957, 4785, 3875, 3838, -1, -1, -1, -1},
        {-1, -1, 67, 99, 265, 376, 232, 223, 4546, 564, -1, -1}
    };
    float highestAverage;
    float highestMedian;
    float currentAverage;
    float currentMedian;

    cout << "Before sorting:\n";
    for (int i = 0; i < NUM_AGENTS; i++)
    {
        printSales(sales[i], NUM_MONTHS);
        qsort(sales[i], NUM_MONTHS, sizeof(int), compareFunction);
    }
    cout << "\n";

    cout << "After sorting:\n";
    for (int i = 0; i < NUM_AGENTS; i++)
        printSales(sales[i], NUM_MONTHS);
        
    cout << "\n";


    highestAverage = findAverage(sales[0], NUM_MONTHS);
    highestMedian = findMedian(sales[0], NUM_MONTHS);

    // Find highest average
    for (int i = 1; i < NUM_AGENTS; i++)
    {
        currentAverage = findAverage(sales[i], NUM_MONTHS);
        currentMedian = findMedian(sales[i], NUM_MONTHS);

        if (currentAverage > highestAverage)
            highestAverage = currentAverage;
        if (currentMedian > highestMedian)
            highestMedian = currentMedian;
    }


    cout << "\nThe highest sales average is: " << highestAverage << "\n";
    cout << "The highest sales median is: " << highestMedian << "\n";

    return 0;
}
