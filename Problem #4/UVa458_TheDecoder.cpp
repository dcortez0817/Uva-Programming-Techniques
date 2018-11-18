//UVa458_TheDecoder: Darien Cortez: hastyhooligan

#include <iostream>
#include <string>

using namespace std;

int main()
{
	string line;

	while (getline(cin, line))
	{
		for (int i = 0; i < line.length(); i++)
		{
			line[i] = int(line[i]) - 7;
		}
		cout << line << '\n';
	}

	return 0;
}