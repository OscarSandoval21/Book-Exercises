#include <iostream>
#include <string>
#include <algorithm>
using std::cout;
using std::cin;
using std::string;

/*
    If the number given is in binary or hex, I need to convert to decimal first, and then convert to the
    necessary output
*/

int binaryToDecimal() {
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

    return decimalNumber;
}



string decimalToBinary(int number) {
    int decimalNumber;
    string binaryNumber = "";
    int position = 1;
    int digit;

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
    reverse(binaryNumber.begin(), binaryNumber.end());

    return binaryNumber;
}


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


string decimalToHex(int number) {
    int decimalNumber;
    string hexNumber = "";
    int digit;

    decimalNumber = number;

    while (number > 15)
    {   
        digit = number % 16;

        findDigit(digit, hexNumber);
        
        number /= 16;
    }

    findDigit(number, hexNumber);
    reverse(hexNumber.begin(), hexNumber.end());

    return hexNumber;
}



int hexToDecimal() {
    char digit;
    int decimalNumber = 0;
    string hexNumber = "";

    cout << "Enter a hexadecimal number: ";
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

    return decimalNumber;
}



int main() {
    char base;
    int binaryNumber;
    int decimalNumber;
    string hexNumber;

    cout << "This program will convert a number you input from\n"
                << "and to binary, decimal, or hexadecimal.\n";
    cout << "Enter the base of your number input: (b)inary, (d)ecimal, or (h)exadecimal.\n";
    base = cin.get();
    cin.get();

    switch(base)
    {
        case 'b':
            decimalNumber = binaryToDecimal();
            break;
        case 'd':
            cout << "Enter a decimal number: ";
            cin >> decimalNumber;
            break;
        case 'h':
            decimalNumber = hexToDecimal();
            break;
        default:
            cout << "There was an error.\n";
            return 0;
            break;
    }

    cout << "Binary: " << decimalToBinary(decimalNumber) << "\n";
    cout << "Decimal: " << decimalNumber << "\n";
    cout << "Hexadecimal: " << decimalToHex(decimalNumber) << "\n";

    return 0;
}