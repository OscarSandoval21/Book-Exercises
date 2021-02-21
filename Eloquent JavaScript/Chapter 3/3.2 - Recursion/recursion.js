/*
    Recursion

    We’ve seen that % (the remainder operator) can be used to test whether a
    number is even or odd by using % 2 to see whether it’s divisible by two. Here’s
    another way to define whether a positive whole number is even or odd:
        • Zero is even.
        • One is odd.
        • For any other number N, its evenness is the same as N - 2.

    Define a recursive function isEven corresponding to this description. The
    function should accept a single parameter (a positive, whole number) and return
    a Boolean.
    Test it on 50 and 75. See how it behaves on -1. Why? Can you think of a
    way to fix this?


    > When testing with -1, it would return undefined. However, I fixed it by first
    checking whether the number may be negative. If it is, use the unary - operator
    to change its sign back to positive.
*/

function isEven(number)
{
    if (number < 0)
        number = -number;

    if (number === 0 || number === 1)
        return number == 0;
    else
        return isEven(number - 2);
}

window.onload = function()
{
    console.log(isEven(50));
    console.log(isEven(75));
    console.log(isEven(-1));
}