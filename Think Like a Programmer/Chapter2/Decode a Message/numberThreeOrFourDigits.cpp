#include <iostream>
using std::cout;
using std::cin;

int main() {
    char digit;
    int number = 0;

    cout << "Enter a number: ";

    digit = cin.get();

    while (digit != 10)
    {
        if (number > 0)
            number *= 10;
        
        number += digit - '0';

        digit = cin.get();
    }

    cout << "The number you entered is: " << number << "\n";
    
    return 0;
}