/*
    Reversing an array

    Arrays have a reverse method that changes the array by inverting the order in
    which its elements appear. For this exercise, write two functions, reverseArray
    and reverseArrayInPlace. The first, reverseArray, takes an array as argument
    and produces a new array that has the same elements in the inverse order. The
    second, reverseArrayInPlace, does what the reverse method does: it modifies
    the array given as argument by reversing its elements. Neither may use the
    standard reverse method.
        Thinking back to the notes about side effects and pure functions in the
    previous chapter, which variant do you expect to be useful in more situations?
    Which one runs faster?

    > reverseArray would be useful in more situations because it returns a value,
    as opposed to reverseArrayInPlace, which produces a side effect. reverseArray
    can produce the same result as reverseArrayInPlace, and could be used in more,
    different ways.
    > reverseArrayInPlace runs faster because it only has to iterate over half of
    the array, as opposed to reverseArray, which has to iterate over the whole
    array and copy its contents one by one.
*/

function reverseArray(array)
{
    let newArray = [];

    for (let i = array.length - 1; i >= 0; i--)
        newArray.push(array[i]);

    return newArray;
}

function reverseArrayInPlace(array)
{
    let temp;

    for (let i = 0; i < (array.length / 2); i++)
    {
        temp = array[i];
        array[i] = array[(array.length - 1) - i];
        array[(array.length - 1) - i] = temp;
    }
}

window.onload = function()
{
    let array = ['hello', 'world'];
    console.log(...reverseArray(array));
    console.log(...array);
    reverseArrayInPlace(array);
    console.log(...array);
}