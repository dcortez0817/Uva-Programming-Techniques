//UVa11572 : Darien Cortez : hastyhooligan

#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
	int t, n, num;
	cin >> t;//number of test cases

	while (t--)
	{
		map<int, int> snowflake;//snowflake identifier
		//cnt = counter; lg = longest unique sequence; pval = past index value of num key 
		int lg = 0, pval = 0;

		cin >> n;//number of snowflakes processed by the machine
		snowflake.clear();

		//index (i) acts as a counter of unique numbers
		for (int i = 1; i <= n; i++)
		{
			cin >> num;
			
			pval = max(pval, snowflake[num]);//sets the last index occurence of num to pval
			snowflake[num] = i;//updates value for num key
			lg = max(lg, i - pval);//subtracts current pval from current i
		}
		cout << lg << endl;

	}
	return 0;
}