#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::string;

char changeMode(int &modeNumber)
{
    char modes[] = {'U', 'L', 'P'};
    int index = modeNumber % 3;
    char newMode;

    newMode = modes[index];
    modeNumber++;

    return newMode;
}

char getLetter(int number, char mode)
{
    char character;

    // Uppercase alphabet starts at 65 on ASCII code and ends at 90
    // Lowercase alphabet starts at 97 and ends at 122
    if (mode == 'U')
    {
        // number += 64;
        number += 'A' - 1;
    }
    else
    {
        // number += 96;
        number += 'a' - 1;
    }
    
    character = number;

    return character;
}

char getPunctuation(int number)
{
    char punctuation[] = {'!', '?', ',', '.', ' ', ';', '"', '\''};

    return punctuation[--number];
}

void output(string number)
{
    cout << "You entered: " << number << "\n";
}

char processInput(string numberString, char& mode, int& modeNumber)
{
    int number = 0;
    char character = 0;

    number = std::stoi(numberString);

    if (mode == 'P')
    {
        number %= 9;

        if (number == 0)
            mode = changeMode(modeNumber);
        else
            character = getPunctuation(number);
    }
    else
    {
        number %= 27;

        if (number == 0)
            mode = changeMode(modeNumber);
        else
            character = getLetter(number, mode);
    }

    return character;
}

int main() {
    int modeNumber = 0;
    char mode = changeMode(modeNumber);
    char character;
    string textStream = "";
    string decodedMessage = "";


    cout << "Enter a message: ";
    character = cin.get();

    // 10 is the carriage return ASCII code
    while (character != 10)
    {
        if (character == ',')
        {
            decodedMessage += processInput(textStream, mode, modeNumber);
            textStream = "";
        }
        else
            textStream += character;

        character = cin.get();
    }

    decodedMessage += processInput(textStream, mode, modeNumber);

    cout << "The decoded message is: " << decodedMessage << "\n";
    
    
    return 0;
}