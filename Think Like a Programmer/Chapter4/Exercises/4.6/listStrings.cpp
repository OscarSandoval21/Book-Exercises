/*
    4-6. Let’s create an implementation for strings that uses a linked list of characters
    instead of dynamically allocated arrays. So we’ll have a linked list where the
    data payload is a single char; this will allow strings to grow without having to recreate
    the entire string. We’ll start by implementing the append and characterAt
    functions.
*/

/*
    Plan Outline:
    > Need to implement a similar functionality to that of the arrayStrings but with linked lists
    instead. The program will essentially work the same, but the implementation will no longer have
    random access as it did with arrays. Instead, everything will have to be accessed sequentially.
    > The characterAt() function will need to be rewritten, so that the character at the given position
    is accessed through a sequential search. Additionally, a variable will need to keep track of what
    position we are in the list, and this number will be compared to the argument passed to the function.
    > The append() function will no longer need to dynamically create a new array and copy its contents.
        > Instead, the linked list can be expanded by adding the new character to the end of the list.
            > This means that I will need a pointer to keep track of the end of the list, so that I
            won't need to sequentially search through the list each time I want to add a new character.
            > As opposed to the student records, the order of the characters stored in each listString DOES
            matter, so each new character cannot be added to the front of the list, and must therefore be
            added to the end of it.
*/

#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::string;

struct listNode
{
    char character;
    listNode * next;
};

typedef listNode * listString;

void printList(listString str)
{
    while (str != NULL)
    {
        cout << str->character;
        str = str->next;
    }
    cout << "\n";
}

void deleteLinkedList(listString &str)
{
    listNode * temp = str;

    cout << "str: " << str << "\n";
    cout << "temp: " << temp << "\n";

    while (str != NULL)
    {
        str = str->next;
        delete temp;
        temp = str;
    }

    cout << "str: " << str << "\n";
    cout << "temp: " << temp << "\n";
}

char characterAt(listString str, int index)
{
    int position = 0;

    while (str != NULL)
    {
        position++;
        if (position == index)
            return str->character;
        
        str = str->next;
    }

    cout << "That position is out of range.\n";
    return '0';
}

void append(listString &strTail, char character)
{
    if (strTail == NULL)
    {
        strTail = new listNode;
        strTail->character = character;
        strTail->next = NULL;
    }

    strTail->next = new listNode;
    strTail = strTail->next;
    strTail->character = character;
    strTail->next = NULL;
}

// void addCharacter(listString &strTail, char character)
// {
//     if (strTail == NULL)
//     {
//         strTail = new listNode;
//         strTail->character = character;
//         strTail->next = NULL;
//     }

//     strTail->next = new listNode;
//     strTail = strTail->next;
//     strTail->character = character;
//     strTail->next = NULL;
// }

void appendTester()
{
    listNode * strHead = NULL;
    listNode * strTail = NULL;
    cout << "List:\n";
    printList(strHead);
    append(strTail, 'h');
    strHead = strTail;
    printList(strHead);
    append(strTail, 'e');
    printList(strHead);
    append(strTail, 'l');
    printList(strHead);
    append(strTail, 'l');
    printList(strHead);
    append(strTail, 'o');
    printList(strHead);

    int position = 2;
    cout << "The character in position " << position << " is: " 
            << characterAt(strHead, position) << "\n";

    deleteLinkedList(strHead);
    cout << "List after deleting:\n";
    printList(strHead);
}

int main() {
    appendTester();
    
    return 0;
}