#include <iostream>
using std::cout;
using std::cin;

int main() {
    for (int rows = 1; rows <= 4; rows++)
    {
        for (int spaceNumber = 1; spaceNumber < rows; spaceNumber++)
        {
            cout << " ";
        }

        for (int hashNumber = 1; hashNumber <= 8 - ((rows - 1) * 2); hashNumber++)
        {
            cout << "#";
        }

        cout << "\n";
    }
    
    return 0;
}