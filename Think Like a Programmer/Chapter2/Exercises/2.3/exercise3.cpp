#include <iostream>
using std::cout;
using std::cin;
using std::abs;

int main() {
    for (int rows = 1; rows <= 8; rows++)
    {
        // Spaces on the left
        for (int spaceNumber = 1; spaceNumber < 4 - abs(rows - 4.5); spaceNumber++)
        {
            cout << " ";
        }

        // Hashes on the left
        for (int hashNumber = 1; hashNumber < 5 - abs(rows - 4.5); hashNumber++)
        {
            cout << "#";
        }

        // Spaces on top
        for (int spaceNumber = 1; spaceNumber <= 12 - ((rows - 1) * 4); spaceNumber++)
        {
            cout << " ";
        }

        // Spaces on bottom
        for (int spaceNumber = 1; spaceNumber <= ((rows - 5) * 4); spaceNumber++)
        {
            cout << " ";
        }

        // Hashes on the right
        for (int hashNumber = 1; hashNumber < 5 - abs(rows - 4.5); hashNumber++)
        {
            cout << "#";
        }


        cout << "\n";
    }
    
    return 0;
}