/*
    2-5. If you like the Luhn formula problem, try writing a program for a different
    check-digit system, like the 13-digit ISBN system. The program could take an
    identification number and verify it or take a number without its check digit
    and generate the check digit.

    This program will check if a given ISBN-13 number is valid.
*/

#include <iostream>
using std::cout;
using std::cin;

int main() {
    int checksum = 0;
    char digit;
    int position = 1;

    cout << "Enter an ISBN-13 number to verify (no dashes or spaces): ";
    digit = cin.get();

    cout << "You entered: " << digit << "\n";

    // 10 is the end-of-line character
    while (digit != 10)
    {
        digit -= '0';

        // If the position is even
        if (position % 2 == 0)
            checksum += digit * 3;
        else
            checksum += digit;

        position++;
        digit = cin.get();
    }

    cout << "The checksum is: " << checksum << "\n";

    if (checksum % 10 == 0)
        cout << "The checksum is divisible by 10. Valid.\n";
    else
        cout << "The checksum is not divisible by 10. Invalid.\n";

    
    return 0;
}