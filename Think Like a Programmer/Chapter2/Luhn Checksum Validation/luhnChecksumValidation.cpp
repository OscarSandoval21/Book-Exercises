#include <iostream>
using std::cout;
using std::cin;

int getDouble(int number)
{
    int sum = 0;

    number *= 2;
    
    if (number > 9)
        sum = (number / 10) + (number % 10);  // Add the separate digits together
    else
        sum = number;
        
    return sum;
}

int main() {
    char digit;
    int evenChecksum = 0;
    int oddChecksum = 0;
    int checksum;
    int position = 1;
    
    cout << "Enter a number with an even number of digits: ";
    digit = cin.get();

    // 10 is the ASCII code for the ENTER key (carriage return)
    while (digit != 10)
    {
        digit -= '0';

        if (position % 2 == 0)
        {
            evenChecksum += digit;
            oddChecksum += getDouble(digit);
        }
        else
        {
            evenChecksum += getDouble(digit);
            oddChecksum += digit;
        }

        digit = cin.get();
        position++;
    }

    cout << "Your number had " << position - 1 << " digits.\n";

    if ((position - 1) % 2 == 0)
        checksum = evenChecksum;
    else
        checksum = oddChecksum;

    cout << "Checksum is " << checksum << ".\n";

    if (checksum % 10 == 0)
        cout << "Checksum is divisible by 10. Valid.\n";
    else
        cout << "Checksum is not divisible by 10. Invalid.\n";

    
    return 0;
}