/*
    4-10. For the digit list of the previous exercise, write a function that takes two such
    lists and produces a new list representing their sum.
*/

/*
    Plan Outline:
    > The function needs to make a new list out of the sum of two linked lists passed to it.
        > In order to do this, I could write a helper function that returns an integer value
        of the numbers contained in a linked list. I could then get the sum of both integer
        values, and use the same method from intToList to create a new list out of the sum.
    
    > In order to convert a linked list to an integer, I could retrieve each digit in the list
    individually, and multiply the total by 10 for each new digit that I encounter, then add
    the new digit to it.
        > For example, if the number in the list to convert is 132, the first digit will be 1,
        so the integer will only contain 1 to begin with. When the digit 3 is encountered, 1
        will be multiplied by 10 to get 10, and 3 added to it to get 13. Finally, when the digit
        2 is encountered at the end, 13 is multiplied by 10 to get 130, and 2 is added to get 132.
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

listInteger intToList(int numberToStore)
{
    listNode * numberList = new listNode;
    numberList->next = NULL;

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

    return numberList;
}

int listToInt(listInteger numberList)
{
    int number = 0;

    if (numberList != NULL)
    {
        number += numberList->digit;
        numberList = numberList->next;
    }

    while (numberList != NULL)
    {
        number *= 10;
        number += numberList->digit;
        numberList = numberList->next;
    }

    return number;
}

void sumOfLists(listInteger numberList1, listInteger numberList2)
{
    listNode * listSum = NULL;
    int numberToStore = 0;
    int number1 = listToInt(numberList1);
    int number2 = listToInt(numberList2);
    cout << "List 1 has integer: " << number1 << "\n";
    cout << "List 2 has integer: " << number2 << "\n";

    numberToStore = number1 + number2;

    listSum = intToList(numberToStore);
    cout << "Linked list containing sum:\n";
    printList(listSum);

    deleteLinkedList(listSum);
    cout << "Sum list after deletion:\n";
    printList(listSum);
}

void sumOfListsTester()
{
    int numberToStore;

    cout << "Enter the number you wish to store in list 1: ";
    cin >> numberToStore;
    listNode * numberList1 = intToList(numberToStore);

    cout << "Enter the number you wish to store in list 2: ";
    cin >> numberToStore;
    listNode * numberList2 = intToList(numberToStore);

    cout << "List 1:\n";
    printList(numberList1);
    cout << "List 2:\n";
    printList(numberList2);

    sumOfLists(numberList1, numberList2);

    deleteLinkedList(numberList1);
    deleteLinkedList(numberList2);
    cout << "Lists after deletion:\n";
    printList(numberList1);
    printList(numberList2);
}

int main() {
    sumOfListsTester();
    return 0;
}