//UVa11350 : Darien Cortez : hastyhooligan

#include <iostream>
#include <string>

using namespace std;

typedef pair<long long, long long> frac;//holds fractions

void SternBrocotTree(string dir, frac begin, frac end)
{
	frac med(begin.first + end.first, begin.second + end.second);//mediant fraction
	if (!dir.empty())//i acts as index
	{
		if (dir[0] == 'R')
		{
			dir = dir.substr(1);//looks at next string
			SternBrocotTree(dir, begin, med);
		}
		else
		{
			dir = dir.substr(1);
			SternBrocotTree(dir, med, end);
		}
	}
	else
		cout << med.first << "/" << med.second << endl;
}

int main()
{
	int N; // number of tests
	string direction;//directions (left or right)
	frac begin(0, 1);//first fraction in tree
	frac end(1, 0);//last fraction in tree

	cin >> N;
	while (N--)
	{
		cin >> direction;
		SternBrocotTree(direction, begin, end);
	}
	return 0;
}