#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::string;

int main() {
    const int NUM_AGENTS = 3;
    const int NUM_MONTHS = 12;
    int sales[NUM_AGENTS][NUM_MONTHS] = {
        {1856, 498, 30924, 87478, 328, 2653, 387, 3754, 387587, 2873, 276, 32},
        {5865, 5456, 3983, 6464, 9957, 4785, 3875, 3838, 4959, 1122, 7766, 2534},
        {23, 55, 67, 99, 265, 376, 232, 223, 4546, 564, 4544, 3434}
    };
    int highestSale = 0;
    int agent;
    int month;

    for (int i = 0; i < NUM_AGENTS; i++)
    {
        for (int j = 0; j < NUM_MONTHS; j++)
        {
            if (sales[i][j] > highestSale)
            {
                highestSale = sales[i][j];
                agent = i + 1;
                month = j + 1;
            }
        }
    }

    cout << "The highest sale was " << highestSale << " by agent " << agent << " on month " <<
            month << "\n";
    
    return 0;
}
