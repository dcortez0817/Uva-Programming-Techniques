// Uva10082_WERTYU.cpp: Darien Cortez: hastyhooligan.

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
	int val;
	string line, keyboard;

	while (getline(cin, line))
	{
		keyboard = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";

		for (int i = 0; i<line.length(); i++)
		{
			if (line[i] == ' ')
				line[i] = ' ';

			else // there are characters in the inputted line other than a space
			{
				for (int j = 0; j < keyboard.length(); j++)
				{
					if (line[i] == keyboard[j])
						line[i] = keyboard[j - 1];
				}
			}
		}
		cout << line << '\n';
	}
	return 0;
}