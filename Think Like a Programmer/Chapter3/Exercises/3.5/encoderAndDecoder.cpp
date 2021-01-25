/*
    3-5. Have the previous program convert the ciphertext back to the plaintext to
    verify the encoding and decoding.
*/

/*
    Plan Outline:
    > In order to decode the message that has been encoded, the same array can be used,
    but it must used backwards, in a way that the subscript of each letter can be used to
    get the original letter of the alphabet.
        - This can be done by first searching the array for the letter that is to be
        decoded. Once found, the subscript value can be added to the character 'A' to
        acquire the original letter of the alphabet that corresponds to that encoded letter.
*/

#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::string;

char encodeMessage(const char cipher[], char letter)
{
    letter %= 'A';

    return cipher[letter];
}

char decodeMessage(const char cipher[], const int ARRAY_SIZE, char letter)
{
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        if (letter == cipher[i])
            return (i + 'A');
    }
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
    string decryptedMessage = "";
    
    cout << "Enter a message to encode (Use only uppercase letters and punctuation):\n";
    letter = cin.get();

    while (letter != 10)
    {
        if (letter >= 'A' && letter <= 'Z')
            encriptedMessage += encodeMessage(cipher, letter);
        else
            encriptedMessage += letter;

        letter = cin.get();
    }

    cout << "The encripted message is: " << encriptedMessage << "\n";


    cout << "Enter a message to decode (Use only uppercase letters and punctuation):\n";
    letter = cin.get();

    while (letter != 10)
    {
        if (letter >= 'A' && letter <= 'Z')
            decryptedMessage += decodeMessage(cipher, ARRAY_SIZE, letter);
        else
            decryptedMessage += letter;

        letter = cin.get();
    }

    cout << "The decrypted message is: " << decryptedMessage << "\n";

    
    return 0;
}