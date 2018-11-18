//UVa10815 : Darien Cortez : hastyhooligan

#include <iostream>
#include <set>
#include <string>

using namespace std;

int main()
{
	string w;//each word
	set<string> text;//set for text

	while (cin >> w)
	{
		string dw = "";//converted dictionary word

		//loops through each character of a word and switches
		//characters other than "a - z" to NULL
		for (int i = 0; i < w.length(); i++)
		{
			char c = tolower(w[i]);//sets all letters lowercase

			if (c >= 'a' && c <= 'z')
				dw += c;
				
			else if (dw != "")//ignores blank spaces
			{
			    text.insert(dw);
				dw = "";
			}
		}
		
		if (dw != "")//ignores blank spaces
		    text.insert(dw);
	}

	for (set<string>::iterator it = text.begin(); it != text.end(); it++)
		cout << *it << '\n';
	return 0;
}
