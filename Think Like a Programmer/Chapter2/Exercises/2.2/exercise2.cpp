#include <iostream>
using std::cout;
using std::cin;
using std::abs;

int main() {
    // for (int rows = 1; rows <= 4; rows++)
    // {
    //     for (int spaceNumber = 1; spaceNumber <= 4 - rows; spaceNumber++)
    //     {
    //         cout << " ";
    //     }

    //     for (int hashNumber = 1; hashNumber <= rows * 2; hashNumber++)
    //     {
    //         cout << "#";
    //     }

    //     cout << "\n";
    // }



    for (int rows = 1; rows <= 8; rows++)
    {

        for (int spaceNumber = 1; spaceNumber <= abs(rows - 4.5); spaceNumber++)
        {
            cout << " ";
        }

        for (int hashNumber = 1; hashNumber <= ((5 - abs(rows - 4.5)) * 2) - 1; hashNumber++)
        {
            cout << "#";
        }

        cout << "\n";
    }



    
    // for (int rows = 1; rows <= 4; rows++)
    // {
    //     for (int spaceNumber = 1; spaceNumber < rows; spaceNumber++)
    //     {
    //         cout << " ";
    //     }

    //     for (int hashNumber = 1; hashNumber <= 8 - ((rows - 1) * 2); hashNumber++)
    //     {
    //         cout << "#";
    //     }

    //     cout << "\n";
    // }
    
    return 0;
}