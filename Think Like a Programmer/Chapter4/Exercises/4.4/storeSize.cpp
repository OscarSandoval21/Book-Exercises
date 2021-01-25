/*
    4-4. Change the implementation of our strings such that location[0] in the array
    stores the size of the array (and therefore location[1] stores the first actual
    character in the string), rather than using a null-character terminator.
    Implement each of the three functions, append, concatenate, and charactertAt,
    taking advantage of the stored size information whenever possible. Because
    we’ll no longer be using the null-termination convention expected by the
    standard output stream, you’ll need to write your own output function that
    loops through its string parameter, displaying the characters.
*/

/*
    Plan Outline:

    > The functions need to be changed so that whenever the length of the arrayString
    is used, it is accessed through the array's [0] subscript, meaning that the
    getLength function is no longer necessary.
    > The [0] subscript of each arrayString will hold the value of the size of the
    array, not including the [0] subscript itself. This will make it so that the
    implementation won't require many changes to the previous code.

    Steps:

    + Change all the places where the length is used in functions so that it is accessed
    through the [0] subscript of each arrayString instead.
    + If a subscript was accessed directly before, this will now need to be changed
    accordingly so that it knows that the first position holds the length of the
    arrayString and not any of the characters.
    + Make a function to print the contents of each arrayString.
*/

#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::string;

typedef char * arrayString;

char charAt(arrayString str, int index)
{
    if (index > 0 && index <= str[0])
        return str[index];
    else
    {
        cout << "Invalid range.\n";
        return '0';
    } 
}

void append(arrayString &str, char character)
{
    int oldLength = str[0];

    arrayString newStr = new char[oldLength + 2];
    newStr[0] = oldLength + 1;

    // Copy the original str into the new string
    for (int i = 1; i <= oldLength; i++)
        newStr[i] = str[i];


    newStr[oldLength + 1] = character;

    delete[] str;
    str = newStr;
}

void concatenate(arrayString &str, arrayString str2)
{
    int firstLength = str[0];
    int secondLength = str2[0];

    arrayString newStr = new char[firstLength + secondLength + 1];
    newStr[0] = firstLength + secondLength;

    for (int i = 1; i <= firstLength; i++)
        newStr[i] = str[i];

    for (int i = 1; i <= secondLength; i++)
        newStr[firstLength + i] = str2[i];

    delete[] str;
    str = newStr;
}

void printArrayString(arrayString str)
{
    for (int i = 1; i <= str[0]; i++)
        cout << str[i];

    cout << "\n";
}

void appendTester()
{
    char stringSize = 4;
    arrayString str = new char[stringSize + 1];
    str[0] = stringSize;
    str[1] = 't';
    str[2] = 'e';
    str[3] = 's';
    str[4] = 't';

    append(str, '!');
    printArrayString(str);
    delete[] str;
}

void concatenateTester()
{
    char stringSize = 2;
    arrayString str = new char[stringSize + 1];
    str[0] = stringSize;
    str[1] = 'h';
    str[2] = 'e';

    stringSize = 3;
    arrayString str2 = new char[stringSize + 1];
    str2[0] = stringSize;
    str2[1] = 'l';
    str2[2] = 'l';
    str2[3] = 'o';

    cout << charAt(str, 1) << "\n";

    concatenate(str, str2);
    
    printArrayString(str);
    delete[] str;
    delete[] str2;
}

int main() {
    appendTester();
    concatenateTester();
    return 0;
}