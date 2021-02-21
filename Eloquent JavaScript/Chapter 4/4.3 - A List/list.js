/*
    A List

    let list = {
        value: 1,
        rest: {
            value: 2,
            rest: {
                value: 3,
                rest: null
            }
        }
    };

    Write a function arrayToList that builds up a list structure like the one
    shown when given [1, 2, 3] as argument. Also write a listToArray function
    that produces an array from a list. Then add a helper function prepend, which
    takes an element and a list and creates a new list that adds the element to the
    front of the input list, and nth, which takes a list and a number and returns
    the element at the given position in the list (with zero referring to the first
    element) or undefined when there is no such element.
    If you haven’t already, also write a recursive version of nth.
*/

function arrayToList(array)
{
    if (array.length == 0)
        return {};

    let list = {
        value: array[array.length - 1],
        rest: null
    };

    for (let i = array.length - 2; i >= 0; i--)
    {
        list = {
            value: array[i],
            rest: list
        };
    }

    return list;
}

function listToArray(list)
{
    let array = [];
    let current = list;

    while (current != null)
    {
        array.push(current.value);
        current = current.rest;
    }

    return array;
}

function prepend(element, list)
{
    let newList = {
        value: element,
        rest: list
    };

    return newList;
}

/*
    > I'm given a list and position as arguments. I have to find the element
    stored at the given position, if it exists, otherwise return undefined.
        - To do this, I need to iterate through the list, keeping track of where
        in the list I am, and use this value to compare to the position.
        - I have to continue iterating until I reach the position or until I reach
        the end of the list.
*/
function nth(list, position)
{
    if (position < 0)
        return undefined;

    let currentObject = list;
    let currentPosition = 0;

    while (currentObject != null)
    {
        if (currentPosition == position)
            return currentObject.value;
        
        currentObject = currentObject.rest;
        currentPosition++;
    }

    return undefined;
}

/*
    > How do I know when to stop the recursive function?
        - If I have arrived at null, I need to stop and return undefined
        because it means the value wasn't found.
        - How do I know if I found the value?
            - Every time I call the function recursively, I iterate once
            through the list, and decrease position by 1. If position is
            equal to 0, then it means that I have finished iterating through
            the list and have arrived at the position where the value must
            be found, so this is how I know.
*/
function nthRecursive(list, position)
{
    if (position < 0 || list == null)
        return undefined;
    else if (position == 0)
        return list.value;
    else
        return nthRecursive(list.rest, position - 1);
}

window.onload = function()
{
    let array = [1, 2, 3];
    console.log("Array: " + array);
    let list = arrayToList(array);
    console.log("Array to List: " + list);
    console.log("List to Array: " + listToArray(arrayToList(array)));
    console.log("Prepend: " + prepend(0, list));
    console.log(nth(list, 1));
    console.log(nthRecursive(list, 1));
}