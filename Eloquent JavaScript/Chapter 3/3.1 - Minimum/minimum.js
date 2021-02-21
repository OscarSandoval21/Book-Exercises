/*
    Minimum
    
    The previous chapter introduced the standard function Math.min that returns
    its smallest argument. We can build something like that now. Write a function
    min that takes two arguments and returns their minimum.
*/

function min(number1, number2)
{
    if (number1 < number2)
        return number1;
    else
        return number2;
}

window.onload = function()
{
    console.log(min(3, 5));
    console.log(min(10, 1));
    console.log(min(2, 2));
}