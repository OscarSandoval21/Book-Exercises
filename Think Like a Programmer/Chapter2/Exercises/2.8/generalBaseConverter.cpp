/*
    2-8. Want an extra challenge? Generalize the code for the previous exercise to
    make a program that converts from any number base-16 or less to any other
    number base. So, for example, the program could convert from base-9 to
    base-4.
*/
/*
    Plan Outline:

    > Every base will first need to be converted to decimal, before converting
    to any other base.
    > The user need to be asked what base their input is in. This value can then
    be stored in a variable that can then be used to do the calculations for that
    specified base in a general way.
    > The input must be read character by character, and each digit needs to be
    processed as it goes.
    > Once the input has been obtained, an integer decimal value can be calculated
    and used to make the calculations for converting to any other base.

    Steps:

    - Make a general function to take in any input character by character and return
    a decimal integer.
    - Create a general function that can use the decimal integer and divide by the base
    that the user specifies.
*/


#include <iostream>
#include <string>
#include <algorithm>
using std::cout;
using std::cin;
using std::string;

int convertBases(int baseInput, int baseOutput, string& originalNumber, string& convertedNumber)
{
    char digit;
    int decimalNumber = 0;
    int baseDigit;

    cout << "Enter the number you want to convert: ";
    digit = cin.get();

    while (digit != 10)
    {
        originalNumber += digit;

        if (decimalNumber > 0)
            decimalNumber *= baseInput;

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

    // Number will now hold a decimal value
    if (baseOutput == 10)
        return decimalNumber;

    while (decimalNumber > baseOutput - 1)
    {
        baseDigit = decimalNumber % baseOutput;

        switch (baseDigit)
        {
            case 10:
                convertedNumber += 'A';
                break;
            case 11:
                convertedNumber += 'B';
                break;
            case 12:
                convertedNumber += 'C';
                break;
            case 13:
                convertedNumber += 'D';
                break;
            case 14:
                convertedNumber += 'E';
                break;
            case 15:
                convertedNumber += 'F';
                break;
            default:
                convertedNumber += std::to_string(baseDigit);
                break;
        }

        decimalNumber /= baseOutput;
    }

    convertedNumber += std::to_string(decimalNumber);
    reverse(convertedNumber.begin(), convertedNumber.end());

    return decimalNumber;
}

int main() {
    int baseInput;
    int baseOutput;
    string convertedNumber = "";
    int decimalNumber;
    string originalNumber = "";

    cout << "What base is your input?\n";
    cin >> baseInput;

    cout << "What base do you want to convert to? (Base-16 or below)\n";
    cin >> baseOutput;
    cin.get();

    decimalNumber = convertBases(baseInput, baseOutput, originalNumber, convertedNumber);
    
    if (baseOutput == 10)
        cout << originalNumber << " from base " << baseInput << " is equal to " << decimalNumber << " in base " << baseOutput << "\n";
    else
        cout << originalNumber << " from base " << baseInput << " is equal to " << convertedNumber << " in base " << baseOutput << "\n";

    
    return 0;
}