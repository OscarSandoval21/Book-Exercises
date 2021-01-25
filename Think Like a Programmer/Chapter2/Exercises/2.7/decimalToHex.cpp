#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::string;

void findDigit(int digit, string &hexNumber)
{
    switch (digit)
    {
        case 10:
            hexNumber += "A";
            break;
        case 11:
            hexNumber += "B";
            break;
        case 12:
            hexNumber += "C";
            break;
        case 13:
            hexNumber += "D";
            break;
        case 14:
            hexNumber += "E";
            break;
        case 15:
            hexNumber += "F";
            break;
        default:
            hexNumber += std::to_string(digit);
            break;
    }
}

int main() {
    int number;
    int decimalNumber;
    string hexNumber = "";
    int digit;

    cout << "Enter a decimal number to convert to hexadecimal: ";
    cin >> number;
    decimalNumber = number;

    while (number > 15)
    {   
        digit = number % 16;

        findDigit(digit, hexNumber);
        
        number /= 16;
    }

    findDigit(number, hexNumber);

    cout << decimalNumber << " converted into hexadecimal is: " << hexNumber << "\n";

    
    return 0;
}