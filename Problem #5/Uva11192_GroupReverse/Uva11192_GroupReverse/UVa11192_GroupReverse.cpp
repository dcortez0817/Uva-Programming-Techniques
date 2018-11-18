//UVa11192_GroupReverse: Darien Cortez: hastyhooligan

#include <iostream>
#include <string>

using namespace std;

int main()
{
	string line;
	int G, l, last, s; //G = number of equal length groups
	char temp;

	while (cin >> G && cin >> line)
	{
		l = (line.length() / G); //length of a group
		last = l - 1; //last character of a group that has not been swapped

		for (int i = 0; i < line.length(); i += l)
		{
			s = i;
			for (int j = i + last; j >= s; j--)
			{
				temp = line[j];
				line[j] = line[s];
				line[s] = temp;
				s++;
			}
		}
		cout << line << '\n';
	}
	return 0;
}