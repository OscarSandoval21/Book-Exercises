/*
    This test program will focus on replacing a part of an arrayString with
    another arrayString based on the target arrayString.
*/

/*
    4-3. For our dynamically allocated strings, create a function replaceString that takes
    three parameters, each of type arrayString: source, target, and replaceText.
    The function replaces every occurrence of target in source with replaceText.
    For example, if source points to an array containing abcdabee, target points to
    ab, and replaceText points to xyz, then when the function ends, source should
    point to an array containing xyzcdxyzee.
*/

/*
    Plan Outline:

    > An assumption is made that the string to be replaced IS within the source arrayString.
    This test program will only be focused on replacing that string with the replaceText arrayString.

    Steps:

    - Figure out the length of the new arrayString to be dynamically created.
    - Figure out a way to copy the contents of the source arrayString into the new one
    that will be dynamically created.
        - Compare each letter of source with the first letter of target. If they match,
        start copying the characters from replaceText into source.
        - Once finished, increase value of outer loop by replaceTextLength.
    - Instead of copying the characters to be replaced, use the ones from the replaceText,
    then continue copying the rest of the characters from the source arrayString.
*/

#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::string;

typedef char * arrayString;

int getLength(arrayString str)
{
    int count = 0;

    // Count will hold the amount of letters in the original str
    while(str[count] != 0)
        count++;

    return count;
}

void replaceString(arrayString &source, arrayString target, arrayString replaceText)
{
    int sourceLength = getLength(source);   // 4
    int targetLength = getLength(target);   // 2
    int replaceTextLength = getLength(replaceText);    // 3
    // Need the difference between targetLength and replaceTextLength, so use abs() to avoid negative values
    int newStrLength = sourceLength + abs(targetLength - replaceTextLength);    // 5

    arrayString newStr = new char[newStrLength + 1];

    int index = 0;

    for (int i = 0; i < newStrLength; i++)
    {
        if (source[i] == target[0])
        {
            for (int j = 0; j < replaceTextLength; j++)
            {
                newStr[j + i] = replaceText[j];
            }

            i += replaceTextLength - 1;
            index += targetLength;
        }
        else
        {
            newStr[i] = source[index];
            index++;
        }
    }

    newStr[newStrLength] = 0;
    delete[] source;
    source = newStr;
}

void replaceStringTester()
{
    arrayString source = new char[5];
    source[0] = 'a';
    source[1] = 'b';
    source[2] = 'c';
    source[3] = 'd';
    source[4] = 0;

    arrayString target = new char[3];
    target[0] = 'b';
    target[1] = 'c';
    target[2] = 0;

    arrayString replaceText = new char[4];
    replaceText[0] = 'x';
    replaceText[1] = 'y';
    replaceText[2] = 'z';
    replaceText[3] = 0;

    cout << source << "\n";
    replaceString(source, target, replaceText);
    cout << source << "\n";
    delete[] source;
    delete[] target;
    delete[] replaceText;
}

int main() {
    replaceStringTester();
    return 0;
}