/*
    PROBLEM: FINDING THE MODE

    In statistics, the mode of a set of values is the value that appears most often. Write
    code that processes an array of survey data, where survey takers have responded to
    a question with a number in the range 1–10, to determine the mode of the data set.
    For our purpose, if multiple modes exist, any may be chosen.
*/

/*
    Plan outline:

    > Traverse the whole array of data to find the values that show up the most.
    > If there is more than one mode, any of them may be chosen.

    Steps:

    > Sorting the array of data first will give me an easier way of finding some
    statistics about it, such as finding the median. It can also make finding
    the mode an easier task.
    > Loop through the array from start to finish
        - For every new number value, the mode will begin counting up from 1 for
        every value it encounters that matches the previous number value.
        - A variable will need to keep track of the current highest mode and how
        many times this mode is repeated in the array.
        - Whenever the number value in the array changes, the current mode and the
        times it is repeated must be stored in variables and the value for each
        must be reset to count the new number value in the array.
*/

#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::string;

int main() {
    const int ARRAY_SIZE = 12;
    int surveyData[ARRAY_SIZE] = {4, 7, 9, 8, 9, 7, 3, 9, 9, 3, 3, 10};
    int mode = 0;
    int currentCount = 1;
    int highestCount = 0;
    int start = 0;
    int end = ARRAY_SIZE - 1;

    cout << "The current array is:\n";
    for (int i = start; i <= end; i++)
        cout << surveyData[i] << " ";
    cout << "\n";

    for (int i = start + 1; i <= end; i++)
    {
        for (int j = i; j > start && surveyData[j - 1] > surveyData[j]; j--)
        {
            int temp = surveyData[j - 1];
            surveyData[j - 1] = surveyData[j];
            surveyData[j] = temp;
        }
    }

    cout << "The current array is:\n";
    for (int i = start; i <= end; i++)
        cout << surveyData[i] << " ";
    cout << "\n";

    mode = surveyData[0];

    for (int i = 1; i < ARRAY_SIZE; i++)
    {
        if (surveyData[i] == surveyData[i - 1])
            currentCount++;
        else
        {
            if (currentCount > highestCount)
            {
                highestCount = currentCount;
                mode = surveyData[i - 1];
            }
            
            currentCount = 1;
        }
    }

    if (currentCount > highestCount)
    {
        highestCount = currentCount;
        mode = surveyData[end];
    }

    cout << "The mode is " << mode << ".\n";
    cout << "And it is repeated " << highestCount << " times.\n";
    
    return 0;
}