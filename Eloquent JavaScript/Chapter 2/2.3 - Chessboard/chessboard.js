/*
    Chessboard

    Write a program that creates a string that represents an 8×8 grid, using newline
    characters to separate lines. At each position of the grid there is either a space
    or a "#" character. The characters should form a chessboard.
    Passing this string to console.log should show something like this:
         # # # #
        # # # #
         # # # #
        # # # #
         # # # #
        # # # #
         # # # #
        # # # #
    When you have a program that generates this pattern, define a binding size
    = 8 and change the program so that it works for any size, outputting a grid
    of the given width and height.
*/

window.onload = function()
{
    let evenOutput = "";
    let oddOutput = "";
    let size = 5;

    for (let column = 0; column < size; column++)
    {
        if (column % 2 == 0)
        {
            evenOutput += ' ';
            oddOutput += '#';
        }
        else
        {
            evenOutput += '#';
            oddOutput += ' ';
        }
    }

    for (let row = 0; row < size; row++)
    {
        if (row % 2 == 0)
            console.log(evenOutput);
        else
            console.log(oddOutput);
    }
}