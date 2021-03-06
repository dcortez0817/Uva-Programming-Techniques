//UVa10815 : Darien Cortez : hastyhooligan

#include <iostream>
#include <set>
#include <string>

using namespace std;

int main()
{
	string w;//each word
	set<string> s;//set for text

	while (cin >> w)
	{
		string dw = "";//converted dictionary word

		//loops through each character of a word and switches
		//characters other than "a - z" to NULL
		for (int i = 0; i < w.length(); i++)
		{
			int c = (int)tolower(w[i]);//sets all letters lowercase

			if ((c >= 97 && c <= 122) == false)
				dw += "";
			else
				dw += w[i];
		}
		s.insert(w);
	}

	for (set<string>::iterator it = s.begin(); it != s.end(); it++)
		cout << *it << endl;
	return 0;
}
