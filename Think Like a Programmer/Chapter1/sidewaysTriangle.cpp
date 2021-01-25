#include <iostream>
using std::cout;
using std::cin;

int main() {
    
    for (int rows = 1; rows <= 7; rows++)
    {
        for (int hashNum = 0; hashNum < 4 - abs(rows - 4); hashNum++)
        {
            cout << "*";
        }
        cout << "\n";
    }
    
    return 0;
}