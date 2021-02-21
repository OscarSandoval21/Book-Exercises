/*
    Flattening

    Use the reduce method in combination with the concat method to “flatten”
    an array of arrays into a single array that has all the elements of the original
    arrays.
*/

/*
    Plan Outline

    > Given an array of arrays, I need to convert all the arrays into a single array
    that contains all the elements that all the arrays contained.
    > The reduce method combines elements in an array into a single value.
    > The concat method combines the argument and the array on which the method was used.
*/

window.onload = function()
{
    let array = [[1, 2], [3, 4], [5, 6, 7, 8], [9]];

    console.log(array.reduce((a, b) => a.concat(b)), "");
}