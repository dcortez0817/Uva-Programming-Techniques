// UVa11933.cpp : Darien Cortez : hastyhooligan

#include <iostream>
#include <bitset>

using namespace std;

int main()
{
	int n;//number to be split
	cin >> n;

	while (n != 0)
	{
		bitset<31> num(n);//binary number for n
		bitset<31> a; //a(n)
		bitset<31> b; //b(n)
		int i = 0, count = 1;

		while (i < num.size())
		{
			while (num[i] == 0) 
			{
				i++;//indices
				a[i] = 0;
				b[i] = 0;

				if (i == num.size()-1)
					break;
			}

			//odd indices with ones
			if (count % 2 != 0 && num[i] == 1)
				a[i] = 1;

			//even indices with ones
			else if (count % 2 == 0 && num[i] == 1)
				b[i] = 1;
			
			count++;//number of 1's in n
			i++;//moves to next index
		}
		cout << a.to_ulong() << " " << b.to_ulong() << '\n';
		cin >> n;
	}
	
	return 0;
}
