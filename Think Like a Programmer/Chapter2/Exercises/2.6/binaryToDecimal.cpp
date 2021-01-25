#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::string;

int main() {
    char digit;
    int decimalNumber = 0;
    string binaryNumber = "";
    int position = 1;

    cout << "Enter a binary number to convert to decimal: ";
    digit = cin.get();

    while (digit != 10)
    {   
        binaryNumber += digit;
        if (position % 4 == 0)
            binaryNumber += " ";

        if (decimalNumber > 0)
            decimalNumber *= 2;

        decimalNumber += digit - '0';
        position++;
        digit = cin.get();
    }

    cout << binaryNumber << " converted into decimal is: " << decimalNumber << "\n";

    
    return 0;
}