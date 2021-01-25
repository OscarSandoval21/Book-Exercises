/*
    4-2. For our dynamically allocated strings, create a function substring that takes
    three parameters: an arrayString, a starting position integer, and an integer
    length of characters. The function returns a pointer to a new dynamically
    allocated string array. This string array contains the characters in the original
    string, starting at the specified position for the specified length. The original
    string is unaffected by the operation. So if the original string was abcdefg, the
    position was 3, and the length was 4, then the new string would contain cdef.
*/

/*
    Plan Outline:

    > The substring function has to return a pointer to a dynamically allocated array.
        - This means that an arrayString has to be returned from the function, holding
        the newly allocated string.
    > Get a substring from the original string, and put it in a pointer to be returned
    by the function.
        - The second parameter will determine the starting position on the for-loop, and
        the third parameter will be used to know when the loop should stop. Each character
        in the original string that falls under those conditions will be copied into the
        new dynamically allocated string to be returned. 
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

arrayString substring(arrayString str, int startingPosition, int length)
{
    int start = startingPosition - 1;
    arrayString subStr = new char[length + 1];

    for (int i = start; i < (start + length); i++)
        subStr[i - start] = str[i];

    subStr[length] = 0;

    return subStr;
}

void substringTester()
{
    arrayString str = new char[8];
    str[0] = 'a';
    str[1] = 'b';
    str[2] = 'c';
    str[3] = 'd';
    str[4] = 'e';
    str[5] = 'f';
    str[6] = 'g';
    str[7] = 0;

    arrayString subStr = substring(str, 3, 4);
    cout << subStr << "\n";
    delete[] str;
    delete[] subStr;
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
    substringTester();
    return 0;
}