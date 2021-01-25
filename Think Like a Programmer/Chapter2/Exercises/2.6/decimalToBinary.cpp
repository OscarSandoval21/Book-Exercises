#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::string;

int main() {
    int number;
    int decimalNumber;
    string binaryNumber = "";
    int position = 1;
    int digit;

    cout << "Enter a decimal number to convert to binary: ";
    cin >> number;
    decimalNumber = number;

    while (number > 1)
    {   
        digit = number % 2;
        binaryNumber += std::to_string(digit);

        if (position % 4 == 0)
            binaryNumber += " ";
            
        number /= 2;
        position++;
    }

    binaryNumber += std::to_string(number);

    cout << decimalNumber << " converted into binary is: " << binaryNumber << "\n";

    
    return 0;
}