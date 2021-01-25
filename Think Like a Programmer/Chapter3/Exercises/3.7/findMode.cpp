/*
    3-7. Write a program that is given an array of integers and determines the mode,
    which is the number that appears most frequently in the array.
*/

#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::string;

int main() {
    const int MAX_RESPONSE = 10;
    int histogram[MAX_RESPONSE];
    const int ARRAY_SIZE = 12;
    int surveyData[ARRAY_SIZE] = {4, 7, 3, 8, 9, 7, 3, 9, 9, 3, 3, 10};
    int highestFrequency;
    int mode;

    for (int i = 0; i < MAX_RESPONSE; i++)
        histogram[i] = 0;

    for (int i = 0; i < ARRAY_SIZE; i++)
        histogram[surveyData[i] - 1]++;

    highestFrequency = histogram[0];
    mode = 1;

    for (int i = 1; i < MAX_RESPONSE; i++)
    {
        if (histogram[i] > highestFrequency)
        {
            highestFrequency = histogram[i];
            mode = i + 1;
        }
    }

    cout << "The mode is " << mode << " with a frequency of " << highestFrequency << "\n";
        
    
    return 0;
}
