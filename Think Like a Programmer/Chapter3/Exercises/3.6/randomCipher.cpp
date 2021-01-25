/*
    3-6. To make the ciphertext problem even more challenging, have your program
    randomly generate the cipher array instead of a hard-coded const array.
    Effectively, this means placing a random character in each element of the
    array, but remember that you can’t substitute a letter for itself. So the first
    element can’t be A, and you can’t use the same letter for two substitutions—
    that is, if the first element is S, no other element can be S.
*/

/*
    Plan Outline:
    > Use a random number generator to come up with the random letters to subsitute
    for the original letters.
        - Continue generating random numbers if the letter generated has already been
        used or if the letter matches the original one.
    
    while (randomLetter - 'A' == i && hasBeenUsed())
*/

#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::string;

char encodeMessage(char cipher[], char letter)
{
    letter %= 'A';

    return cipher[letter];
}

char decodeMessage(char cipher[], const int ARRAY_SIZE, char letter)
{
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        if (letter == cipher[i])
            return (i + 'A');
    }
}

bool isAvailable(char cipher[], const int ARRAY_SIZE, char randomLetter)
{
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        if (randomLetter == cipher[i])
            return false;
    }

    return true;
}

char generateRandomLetter(const int ARRAY_SIZE)
{
    char randomNumber;
    // Generate a random number from 0-25
    randomNumber = rand() % ARRAY_SIZE;

    cout << "Number generated is: " << randomNumber + 'A' << "\n";
    return (randomNumber + 'A');
}

void printCipher(char cipher[], const int ARRAY_SIZE)
{
    for (int i = 0; i < ARRAY_SIZE; i++)
        cout << static_cast<char>(i +'A') << ": " << cipher[i] << "\n";
        
    cout << "\n";
}

int main() {
    const int ARRAY_SIZE = 26;
    char cipher[ARRAY_SIZE] = {};
    char randomLetter;
    char letter;
    string encriptedMessage = "";
    string decryptedMessage = "";
    int index = 0;

    srand(time(0));

    randomLetter = generateRandomLetter(ARRAY_SIZE);

    while (index < ARRAY_SIZE)
    {
        cout << "Random letter is: " << int(randomLetter) << "\n";

        if ((randomLetter - 'A') != index && isAvailable(cipher, ARRAY_SIZE, randomLetter))
        {
            cipher[index] = randomLetter;
            index++;
        }

        // cout << "The current cypher is:\n";
        // printCipher(cipher, ARRAY_SIZE);

        if (index == (ARRAY_SIZE - 1) && isAvailable(cipher, ARRAY_SIZE, (ARRAY_SIZE - 1) + 'A'))
        {
            // cout << "Last letter matches original. Restarting array.\n";
            std::fill_n(cipher, ARRAY_SIZE, 0);
            index = 0;
        }

        randomLetter = generateRandomLetter(ARRAY_SIZE);
    }
    
    cout << "The random cypher is:\n";
    printCipher(cipher, ARRAY_SIZE);
    
    cout << "\nEnter a message to encode (Use only uppercase letters and punctuation):\n";
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


    cout << "\nEnter a message to decode (Use only uppercase letters and punctuation):\n";
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