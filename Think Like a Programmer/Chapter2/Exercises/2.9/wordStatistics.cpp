/* 
    2-9. Write a program that reads a line of text, counting the number of words,
    identifying the length of the longest word, the greatest number of vowels
    in a word, and/or any other statistics you can think of.
*/
/*
    Plan Outline:

    > Read a line of text.
        - Character by character should be able to provide the best method for it
    > Count the number of words in the line of text.
        - An analogy to the "Decode a Message" program where each integer was
        separated by commas; a word would be separated by spaces.
    > Identify the length of the longest word.
        - This can be done with a variable that holds the length.
    > Greatest number of vowels in a word.
        - Again, a variable should suffice.
    > Any other statistics?

    Steps:

    + Take input from user that is read character by character.
    + Create variables that count number of words, length of longest word,
    and greatest number of vowels in a word.
    + Increase counter of words by one every time a space is encountered.
    - For every different word, keep a count of the letters in it and replace
    value accordingly if another word has a greater length.
    - Similarly, keep a count of a word's vowels, and replace that
    of the highest if the current has more vowels than the previous.
    
*/


#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::string;

int main() {
    int numberOfWords = 0;
    int longestLength = 0;
    int currentLength = 0;
    string longestWord = "";
    string currentWord = "";
    int currentVowelCount = 0;
    int mostVowelsCount = 0;
    string mostVowelsWord = "";
    string currentVowelsWord = "";
    char letter;
    char vowels[] = {'A', 'a', 'E', 'e', 'I', 'i', 'O', 'o', 'U', 'u'};

    cout << "Enter a line of text to get some statistics about it:\n";
    letter = cin.get();

    // 10 is the ASCII code for an End-Of-Line
    while (true)
    {
        if (letter == ' ' || letter == 10)
        {
            numberOfWords++;

            if (currentLength > longestLength)
            {
                longestLength = currentLength;
                longestWord = currentWord;
            }
            if (currentVowelCount > mostVowelsCount)
            {
                mostVowelsCount = currentVowelCount;
                mostVowelsWord = currentVowelsWord;
            }

            currentLength = 0;
            currentWord = "";
            currentVowelCount = 0;
            currentVowelsWord = "";

            if (letter == 10)
                break;
        }
        else
        {
            if ((letter >= 'a' && letter <= 'z') || (letter >= 'A' && letter <= 'Z'))
            {
                currentWord += letter;
                currentLength++;
                currentVowelsWord += letter;

                if (letter == 'a' || letter == 'A' || letter == 'e' || letter == 'E' || letter == 'i' ||
                        letter == 'I' || letter == 'o' || letter == 'O' || letter == 'u' || letter == 'U')
                    currentVowelCount++;
            }
            else if (letter == '\'')
            {
                currentWord += letter;
                currentVowelsWord += letter;
            }
        }
        

        letter = cin.get();
    }

    cout << "\nStatistics:\n";
    cout << "The total number of words in the line of text is " << numberOfWords << "\n";
    cout << "The first longest word is \"" << longestWord << "\" with a length of " << longestLength << "\n";
    cout << "The first word with the most vowels is \"" << mostVowelsWord << "\" with " << mostVowelsCount << " vowels.\n";

    return 0;
}