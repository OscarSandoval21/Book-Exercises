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

typedef char* arrayString;

int getLength(arrayString str)
{
    int count = 0;

    // Count will hold the amount of letters in the original str
    while (str[count] != 0)
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

void replaceString(arrayString& source, arrayString target, arrayString replaceText)
{
    int sourceLength = getLength(source);   // 7
    int targetLength = getLength(target);   // 2
    int replaceTextLength = getLength(replaceText);    // 3
    int newStrLength = sourceLength + ((replaceTextLength - targetLength) * getTargetCount(source, target));    // 9

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
    cout << "Original length was: " << getLength(source) + 1 << "\n";
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