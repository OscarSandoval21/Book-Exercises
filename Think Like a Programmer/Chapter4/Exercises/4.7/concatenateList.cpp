/*
    4-7. Following up on the previous exercise, implement the concatenate function.
    Note that if we make a call concatenate(s1, s2), where both parameters are
    pointers to the first nodes of their respective linked lists, the function should
    create a copy of each of the nodes in s2 and append them to the end of s1.
    That is, the function should not simply point the next field of the last node in
    s1’s list to the first node of s2’s list.
*/

/*
    Plan Outline:
    > The concatenate function needs to make a copy of the nodes in s2 and add them to the
    end of s1.
        > The function will be passed a pointer to the first nodes of each listString, which
        means that the first listString will have to be accessed sequentially until we get to
        the end of it. Once at the end, I can use the append function to create copies of
        the characters in the second string and add them to the first string.
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

void concatenate(listString &str, listString str2)
{
    cout << "Link 2 address inside function: " << str2 << "\n";
    listNode * current = str;
    listNode * current2 = str2;

    while (current->next != NULL)
        current = current->next;

    while (current2 != NULL)
    {
        append(current->next, current2->character);
        current = current->next;
        current2 = current2->next;
    }
}

void concatenateTester()
{
    listNode * strHead = NULL;
    listNode * strTail = NULL;
    cout << "List 1:\n";
    printList(strHead);
    append(strTail, 'h');
    strHead = strTail;
    printList(strHead);
    append(strTail, 'e');
    printList(strHead);

    listNode * str2Head = NULL;
    listNode * str2Tail = NULL;
    cout << "List 2:\n";
    printList(str2Head);
    append(str2Tail, 'l');
    str2Head = str2Tail;
    printList(str2Head);
    append(str2Tail, 'l');
    printList(str2Head);
    append(str2Tail, 'o');
    printList(str2Head);

    cout << "Link 2 address outside function: " << str2Head << "\n";

    concatenate(strHead, str2Head);
    cout << "Link after concatenation:\n";
    printList(strHead);

    deleteLinkedList(strHead);
    deleteLinkedList(str2Head);
    cout << "Lists after deleting:\n";
    printList(strHead);
    printList(str2Head);
}

int main() {
    concatenateTester();
    
    return 0;
}