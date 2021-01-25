#include <iostream>
using std::cout;
using std::cin;

int main() {
    
    int number;
    int numberOfPositive = 0;
    int numberOfNegative = 0;
    char answer;

    cout << "Enter 10 numbers\n";
    cin >> number;

    for (int i = 0; i < 10; i++)
    {
        if (number < 0)
            numberOfNegative++;
        else
            numberOfPositive++;

        cin >> number;
    }

    cout << "Which would you like to display? (negative or positive)\n";
    answer = cin.get();

    if (answer == 'n')
        cout << numberOfNegative;
    else
        cout << numberOfPositive;
    
    return 0;
}