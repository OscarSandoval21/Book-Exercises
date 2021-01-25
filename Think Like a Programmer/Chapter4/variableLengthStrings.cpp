/*
    PROBLEM: VARIABLE-LENGTH STRING MANIPULATION

    Write heap-based implementations for three required string functions:

        append: This function takes a string and a character and appends the character
        to the end of the string.
        concatenate: This function takes two strings and appends the characters of the
        second string onto the first.
        characterAt: This function takes a string and a number and returns the character
        at that position in the string (with the first character in the string numbered zero).

    Write the code with the assumption that characterAt will be called frequently,
    while the other two functions will be called relatively seldom. The relative efficiency of
    the operations should reflect the calling frequency.
*/

/*
    Plan Outline:

    > The append function needs to increase the original array size by one, and add the character
    passed to the function to the end of the array.
    > The concatenate function will combine two different strings together.
        - The second string must be added to the end of the first, right after the first string ends.
            ~ Once we have the length of the new string, the contents of the first string have to be
            copied into it, followed by the contents of the second string.
        - This means that the new string will have the length of both strings combined, plus the null
        terminating character.
            ~ If the first string contains 3 letters, plus the null, and the other string contains 5 letters,
            plus the null, then the resulting string must have 8 letters plus the null.
        - After concatenating the second string to the first, the original string will now contain both
        strings together, replacing the original first string on its own.
        
*/

#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::string;

typedef char * arrayString;

char charAt(arrayString str, int index)
{
    return str[index];
}

int getLength(arrayString str)
{
    int count = 0;

    // Count will hold the amount of letters in the original str
    while(str[count] != 0)
        count++;

    return count;
}

void append(arrayString &str, char character)
{
    int oldLength = getLength(str);

    arrayString newStr = new char[oldLength + 2];

    // Copy the original str into the new string
    for (int i = 0; i < oldLength; i++)
        newStr[i] = str[i];


    newStr[oldLength] = character;
    newStr[oldLength + 1] = 0;

    delete[] str;
    str = newStr;
}

void concatenate(arrayString &str, arrayString str2)
{
    int firstLength = getLength(str);
    int secondLength = getLength(str2);

    arrayString newStr = new char[firstLength + secondLength + 1];

    for (int i = 0; i < firstLength; i++)
        newStr[i] = str[i];

    for (int i = 0; i < secondLength; i++)
        newStr[firstLength + i] = str2[i];

    newStr[firstLength + secondLength] = 0;
    delete[] str;
    str = newStr;
}

void appendTester()
{
    arrayString str = new char[5];
    str[0] = 't';
    str[1] = 'e';
    str[2] = 's';
    str[3] = 't';
    str[4] = 0;

    append(str, '!');
    cout << str << "\n";
    delete[] str;
}

void concatenateTester()
{
    arrayString str = new char[3];
    str[0] = 'h';
    str[1] = 'e';
    str[2] = 0;

    arrayString str2 = new char[4];
    str2[0] = 'l';
    str2[1] = 'l';
    str2[2] = 'o';
    str2[3] = 0;

    concatenate(str, str2);
    
    cout << str << "\n";
    delete[] str;
    delete[] str2;
}

int main() {
    appendTester();
    return 0;
}