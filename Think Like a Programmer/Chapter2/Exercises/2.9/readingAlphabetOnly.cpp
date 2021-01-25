#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::string;

int main() {
    char letter;

    cout << "Enter a letter: ";
    letter = cin.get();
    if ((letter >= 'a') && (letter <= 'z'))
        cout << "It's in the alphabet!\n";
    else
    {
        cout << "It's not a letter!\n";
    }

    cout << letter << "\n";
    cout << letter - 'a' << "\n";
    cout << letter - 'z' << "\n";
    
    return 0;
}