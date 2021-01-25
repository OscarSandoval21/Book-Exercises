#include <iostream>
using std::cout;
using std::cin;

int main() {
    
    for (int i = 5; i > 0; i--)
    {
        int count = i;
        
        while(count-- > 0)
        {
            cout << "*";
        }
        
        cout << "\n";
    }

    return 0;
}