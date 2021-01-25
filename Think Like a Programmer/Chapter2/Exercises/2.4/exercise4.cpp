/*
    2-4. Design your own: Think up your own symmetrical pattern of hash marks,
    and see whether you can write a program to produce it that follows the
    shapes rule.

      ##
     #  #
    #    #
    #    #
     #  #
      ##
*/


#include <iostream>
using std::cout;
using std::cin;

int main() {
    for (int rows = 1; rows <= 3; rows++)
	{
		for (int spaces = 1; spaces <= 3 - rows; spaces++)
		{
			cout << " ";
		}

		cout << "#";

		for (int spaces = 1; spaces <= ((rows - 1) * 2); spaces++)
		{
			cout << " ";
		}

		cout << "#";

		cout << "\n";
	}

	for (int rows = 1; rows <= 3; rows++)
	{
		for (int spaces = 1; spaces < rows; spaces++)
		{
			cout << " ";
		}

		cout << "#";

		for (int spaces = 1; spaces <= 6 - (rows * 2); spaces++)
		{
			cout << " ";
		}

		cout << "#";

		cout << "\n";
	}
     
    return 0;
}