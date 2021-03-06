// UVa673.cpp : Darien Cortez : hastyhooligan

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
	int n;//number of strings
	string line;
	
	cin >> n;
	cin.ignore(); //ignores new line
	while(n--)//loops until n = 0
	{
		stack<char> B;
		getline(cin, line);

		for (int j = 0; j < line.length(); j++)
		{
			if (line[j] == '(' || line[j] == '[')
				B.push(line[j]);

			//pop close parentheses if an open parentheses is at the top of the stack
			//if not, push random letter ('r')
			else if (line[j] == ')')
			{
				if (B.empty() || B.top() != '(')
					B.push('r');

				else
					B.pop();
			}

			//pop close bracket if an open bracket is at the top of the stack
			//if not, push random letter ('r')
			else if (line[j] == ']')
			{
				if (B.empty() || B.top() != '[')
					B.push('r');

				else
					B.pop();
			}
		}
		if (B.empty())
			cout << "Yes" << endl;

		else
			cout << "No" << endl;
	}
	
	return 0;
}