/*
    4-8. Add a function to the linked-list string implementation called removeChars to
    remove a section of characters from a string based on the position and length.
    For example, removeChars(s1, 5, 3) would remove the three characters starting
    at the fifth character in the string. Make sure the removed nodes are properly
    deallocated.
*/

/*
    Plan Outline:
    > The function will take a listString and remove a part of it, based on the numbers
    passed as arguments.
        > In order to be removed from the linked lists, those nodes need to be deattached
        and deallocated accordingly so that there are no memory leaks.
            > Two pointers will be required for the removal of the substring. One will
            keep track of the node before the ones to be removed. The other will be used
            to remove the nodes within the substring. Once the last node to be removed is
            reached, its next node will be assigned to the "next" property of the first
            pointer so that the connection will be maintained with the remaining nodes.
        > A variable will be used to keep track of what position we are in the node.
            > This variable will then be used to determine where the substring to be
            removed begins, and when we should stop.
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

void removeChars(listString &str, int begin, int length)
{
    listNode * current = str;
    listNode * nodesToKeep = str;
    listNode * nodeToDelete = NULL;
    int position = 1;

    // Special case, when the position to begin removing starts at the first node.
    if (begin == 1)
    {
        while (position != (begin + length))
        {
            nodeToDelete = current;
            current = current->next;
            delete nodeToDelete;
            position++;
        }

        str = current;
        return;
    }
    else if (begin <= 0)
    {
        cout << "That position does not exist.\n";
        return; 
    }
    

    // Loop to get to the correct position so that it stops at the node just before
    // the ones to be deleted.
    while (position != begin - 1)
    {
        nodesToKeep = nodesToKeep->next;
        position++;
    }

    cout << "The last character to keep before gap is: " << nodesToKeep->character << "\n";
    // nodesToKeep is in node e, current is in l
    // I want to connect nodesToKeep (e) to the remaining characters after removing the
    // substring. So it should be connected to o at the end.
    current = nodesToKeep->next;
    position++;
    cout << "The first character to remove is: " << current->character << "\n";
    nodeToDelete = current;

    while (position != (begin + length))
    {
        nodeToDelete = current;
        current = current->next;
        delete nodeToDelete;
        position++;
    }

    nodesToKeep->next = current;
}

void removeCharsTester()
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

    removeChars(strHead, 1, 2);
    cout << "Link after removing substring:\n";
    printList(strHead);

    deleteLinkedList(strHead);
    cout << "List after deleting:\n";
    printList(strHead);
}

int main() {
    removeCharsTester();
    return 0;
}