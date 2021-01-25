/*
    This iteration of the program will focus on finding the number of times
    the target arrayString appears within the source arrayString in order to
    be replaced.
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

    + Figure out how many times the target string appears within the source string.
        + Have a helper function that counts and returns the amount of times the first
        letter of the target arrayString is found within the source arrayString.
            + This isn't ideal, but will do the job for now. I can later find a better
            way to determine whether the whole target arrayString is found within the
            array.
        + If the first character from the target matches one from the source, have a loop
        that checks to see if the rest of the target letters match.
            + If they do, only then will targetCount increase. Otherwise, targetCount stays the
            same and the outer loop continues checking for matches.
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

int getTargetCount(arrayString source, arrayString target)
{
    int sourceLength = getLength(source);   // 7
    int targetLength = getLength(target);   // 2
    int targetCount = 0;
    bool matches = true;

    for (int i = 0; i < sourceLength; i++)
    {
        if (source[i] == target[0])
        {
            for (int j = 1; j < targetLength; j++)
            {
                if (source[i + j] != target[j])
                {
                    matches = false;
                    break;
                }
            }

            if (matches)
                targetCount++;
        }

        matches = true;
    }

    cout << "TargetCount is: " << targetCount << "\n";

    return targetCount;
}

void replaceString(arrayString &source, arrayString target, arrayString replaceText)
{
    int sourceLength = getLength(source);   // 7
    int targetLength = getLength(target);   // 2
    int replaceTextLength = getLength(replaceText);    // 3
    // Need the difference between targetLength and replaceTextLength, so use abs() to avoid negative values
    int newStrLength = sourceLength + (abs(targetLength - replaceTextLength) * getTargetCount(source, target));    // 9

    cout << "newStr will have length of: " << newStrLength + 1 << "\n";
    arrayString newStr = new char[newStrLength + 1];

    int index = 0;
    int i = 0;
    bool matches = true;

    while (i < newStrLength)
    {
        if (source[index] == target[0])
        {
            for (int j = 1; j < targetLength; j++)
            {
                if (source[index + j] != target[j])
                {
                    cout << "Compared " << source[index + j] << " and " << target[j] << "\n";
                    cout << "Does not match." << "\n";
                    matches = false;
                    break;
                }
            }

            if (matches)
            {
                for (int j = 0; j < replaceTextLength; j++)
                {
                    newStr[j + i] = replaceText[j];
                }
                // newStr[3] is set, we need 4 now
                // i = 1
                // index = 1

                i += replaceTextLength; // 4
                index += targetLength; // 3
            }
            else
            {
                newStr[i] = source[index];
                index++;
                i++;
            }
        }
        else
        {
            newStr[i] = source[index];
            index++;
            i++;
        }

        matches = true;
    }

    newStr[newStrLength] = 0;
    delete[] source;
    source = newStr;
}

void replaceStringTester()
{
    arrayString source = new char[9];
    source[0] = 'a';
    source[1] = 'b';
    source[2] = 'a';
    source[3] = 'd';
    source[4] = 'b';
    source[5] = 'a';
    source[6] = 'b';
    source[7] = 'e';
    source[8] = 0;

    arrayString target = new char[3];
    target[0] = 'a';
    target[1] = 'b';
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