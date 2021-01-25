#include <iostream>
using std::cout;
using std::cin;

int main() {
    // for (int rows = 0; rows < 4; rows++)
    // {
    //     for (int hashNumber = 0; hashNumber < 4 - rows; hashNumber++)
    //     {
    //         cout << "#";
    //     }

    //     cout << "\n";
    // }

    for (int rows = 0; rows < 4; rows++)
    {
        for (int hashNumber = 0; hashNumber < rows; hashNumber++)
        {
            cout << "#";
        }

        cout << "\n";
    }

    
    return 0;
}