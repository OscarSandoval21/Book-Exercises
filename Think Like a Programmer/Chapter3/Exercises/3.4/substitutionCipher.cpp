/*
    3-4. Here’s a variation on the array of const values. Write a program for creating a
    substitution cipher problem. In a substitution cipher problem, all messages
    are made of uppercase letters and punctuation. The original message is called
    the plaintext, and you create the ciphertext by substituting each letter with
    another letter (for example, each C could become an X). For this problem,
    hard-code a const array of 26 char elements for the cipher, and have your
    program read a plaintext message and output the equivalent ciphertext.
*/

/*
    Plan Outline:
    > Need to hardcode a const array of 26 char elements that will act as the cipher.
        - In order to get the order of the cipher, I will create an array that randomly
        assigns unique letters of the alphabet to each spot in the array.
        - I will need to make a function that checks to see if a value is already
        within the array. If it is, then the loop will produce another random number to
        be added to the array until the number is available.
    > Once I have the const array, I will be able to use it to convert to and from the
    cipher by accessing the elements within the array.
        - I can do a sequential search to find the matching substitution character for the
        given character.
    > Read user input character by character. The input must be all uppercase letters and
    punctuation only.
*/

#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::string;

char cipherMessage(const char cipher[], char letter)
{
    letter %= 'A';

    return cipher[letter];
}

int main() {
    const int ARRAY_SIZE = 26;
    const char cipher[ARRAY_SIZE] = {
        'Z', 'Y', 'X', 'W', 'V', 'U', 'T', 'S', 'R', 'Q', 'P', 'O', 
        'N', 'M', 'L', 'K', 'J', 'I', 'H', 'G', 'F', 'E', 'D', 'C', 
        'B', 'A'
    };
    char letter;
    string encriptedMessage = "";
    
    cout << "Enter a message to encode (Use only uppercase letters and punctuation):\n";
    letter = cin.get();

    while (letter != 10)
    {
        if (letter >= 'A' && letter <= 'Z')
            encriptedMessage += cipherMessage(cipher, letter);
        else
            encriptedMessage += letter;

        letter = cin.get();
    }

    cout << "The encripted message is: " << encriptedMessage << "\n";

    
    return 0;
}