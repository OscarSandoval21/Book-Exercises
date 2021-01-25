/*
    2-5. If you like the Luhn formula problem, try writing a program for a different
    check-digit system, like the 13-digit ISBN system. The program could take an
    identification number and verify it or take a number without its check digit
    and generate the check digit.

    This program will calculate the check digit, given the other 12 digits of an
    ISBN-13 number.
*/

#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::string;

int main() {
    int checksum = 0;
    char digit;
    int position = 1;
    int checkDigit;
    string isbn = "";

    cout << "Enter an ISBN-13 number to verify (no dashes or spaces): ";
    digit = cin.get();

    // 10 is the end-of-line character
    while (digit != 10)
    {

        isbn += digit;

        digit -= '0';

        if (position == 3 || position == 4 || position == 9 || position == 12)
            isbn += '-';

        // If the position is even
        if (position % 2 == 0)
            checksum += digit * 3;
        else
            checksum += digit;

        position++;
        digit = cin.get();
    }

    cout << "The checksum is: " << checksum << "\n";

    checkDigit = 10 - (checksum % 10);
    isbn += std::to_string(checkDigit);

    cout << "The check digit for that ISBN-13 number is: " << checkDigit << "\n";

    cout << "The full ISBN-13 number (including the check digit) is:\n" << isbn << "\n";

    
    return 0;
}