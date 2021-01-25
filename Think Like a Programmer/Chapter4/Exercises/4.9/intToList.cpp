/*
    4-9. Imagine a linked list where instead of the node storing a character, the node
    stores a digit: an int in the range 0–9. We could represent positive numbers
    of any size using such a linked list; the number 149, for example, would be a
    linked list in which the first node stores a 1, the second a 4, and the third and
    last a 9. Write a function intToList that takes an integer value and produces a
    linked list of this sort. Hint: You may find it easier to build the linked list
    backward, so if the value were 149, you would create the 9 node first.
*/

/*
    Plan Outline:
    > The function will take user input in form of an integer. In order to get ahold of each
    individual digit, I will divide the number by 10 and use the resulting value to store it
    in the linked list. The linked list will add digits backwards, as the problem states, so
    by doing it this way, I will be able to get the digits starting from the right, then I
    will just need to append them to the front of the linked list.
        > I will be using the method of adding values to the head of the linked list. So a
        new listNode will be created holding the digit, and its "next" property will point
        to the head. The head pointer will then point to the newly created listNode and
        it will become the new head.
            > Following this method, when the linked list is printed sequentially, it will
            be printed in the correct format in which the integer was entered.

*/

#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::string;

struct listNode
{
    int digit;
    listNode * next;
};

typedef listNode * listInteger;

void printList(listInteger list)
{
    while (list != NULL)
    {
        cout << list->digit;
        list = list->next;
    }
    cout << "\n";
}

void deleteLinkedList(listInteger &list)
{
    listNode * temp = list;

    cout << "list: " << list << "\n";
    cout << "temp: " << temp << "\n";

    while (list != NULL)
    {
        list = list->next;
        delete temp;
        temp = list;
    }

    cout << "list: " << list << "\n";
    cout << "temp: " << temp << "\n";
}

void intToList()
{
    int numberToStore;
    listNode * numberList = new listNode;
    numberList->next = NULL;

    cout << "Enter the number you wish to store in a linked list: ";
    cin >> numberToStore;

    cout << "Digit to store: " << numberToStore % 10 << "\n";
    numberList->digit = numberToStore % 10;
    numberToStore /= 10;

    while (numberToStore > 0)
    {
        listNode * newDigit = new listNode;
        cout << "Digit to store: " << numberToStore % 10 << "\n";
        newDigit->digit = numberToStore % 10;
        newDigit->next = numberList;
        numberList = newDigit;
        numberToStore /= 10;

        newDigit = NULL;
    }

    cout << "List:\n";
    printList(numberList);
    deleteLinkedList(numberList);
    cout << "List after deletion:\n";
    printList(numberList);
}

int main() {
    intToList();
    return 0;
}