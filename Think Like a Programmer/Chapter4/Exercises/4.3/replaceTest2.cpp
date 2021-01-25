/*
    This program will focus on replacing multiple instances of the target arrayString
    passed onto the function replaceString.
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

    > An assumption is made that the string to be replaced is within the source arrayString
    one or more times, and must be replaced accordingly.

    Steps:

    - Figure out how many times the target string appears within the source string.
        - For each time that it appears, replace it with the replaceText string.
        - Need to know this in order to figure out how many spaces the dynamically
        created string will need.
        - Maybe the string could be dynamically created elsewhere? 
        
    *** Cannot complete without first completing test3
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
    int sourceLength = getLength(source);   // 7
    int targetLength = getLength(target);   // 2
    int replaceTextLength = getLength(replaceText);    // 3
    // Need the difference between targetLength and replaceTextLength, so use abs() to avoid negative values
    int newStrLength = sourceLength + abs(targetLength - replaceTextLength);    // 8

    arrayString newStr = new char[newStrLength + 1];

    int index = 0;
    int i = 0;

    while (i < newStrLength)
    {
        if (source[index] == target[0])
        {
            for (int j = 0; j < replaceTextLength; j++)
            {
                newStr[j + i] = replaceText[j];
            }

            i += replaceTextLength;
            index += targetLength;
        }
        else
        {
            newStr[i] = source[index];
            index++;
            i++;
        }
    }

    newStr[newStrLength] = 0;
    delete[] source;
    source = newStr;
}

void replaceStringTester()
{
    arrayString source = new char[8];
    source[0] = 'a';
    source[1] = 'b';
    source[2] = 'c';
    source[3] = 'd';
    source[4] = 'b';
    source[5] = 'c';
    source[6] = 'e';
    source[7] = 0;

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