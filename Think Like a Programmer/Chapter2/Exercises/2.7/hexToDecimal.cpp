#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::string;

int main() {
    char digit;
    int decimalNumber = 0;
    string hexNumber = "";

    cout << "Enter a hexadecimal number to convert to decimal: ";
    digit = cin.get();

    while (digit != 10)
    {   
        hexNumber += digit;
        
        if (decimalNumber > 0)
            decimalNumber *= 16;


        switch (digit)
        {
            case 'A':
                decimalNumber += 10;
                break;
            case 'B':
                decimalNumber += 11;
                break;
            case 'C':
                decimalNumber += 12;
                break;
            case 'D':
                decimalNumber += 13;
                break;
            case 'E':
                decimalNumber += 14;
                break;
            case 'F':
                decimalNumber += 15;
                break;
            default:
                decimalNumber += digit - '0';
                break;
        }

        digit = cin.get();
    }

    cout << hexNumber << " converted into decimal is: " << decimalNumber << "\n";

    
    return 0;
}