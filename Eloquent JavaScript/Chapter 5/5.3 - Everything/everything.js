/*
    Everything

    Analogous to the some method, arrays also have an every method. This one
    returns true when the given function returns true for every element in the array.
    In a way, some is a version of the || operator that acts on arrays, and every is
    like the && operator.
    Implement every as a function that takes an array and a predicate function
    as parameters. Write two versions, one using a loop and one using the some
    method.
*/

function every(array, testFunction)
{
    for (let item of array)
    {
        if (!testFunction(item))
            return false;
    }

    return true;
}

/*
    > The some method returns true if an item of an array gives a result
    of true.
        - Only one item has to be true for the function to return true.
        - If it returns false, then it means all of the values are false.
    > The every method returns true only if every item of an array give a result
    of true.
        - If any item in the array fails the test function, then it will return false.


    ***I looked at the solution for this exercise.
*/
function everySome(array, testFunction)
{
    return !array.some(item => !testFunction(item));
}

window.onload = function()
{

}