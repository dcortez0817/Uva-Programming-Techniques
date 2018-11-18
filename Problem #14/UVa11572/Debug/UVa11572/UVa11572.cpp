//UVa11572 : Darien Cortez : hastyhooligan

#include <iostream>
#include <map>

using namespace std;

int main()
{
	int t, n, num;
	
	cin >> t;//number of test cases

	while (t--)
	{
		map<int, int> snowflake;//snowflake identifier
		int cnt = 0, max = 0;

		cin >> n;//number of snowflakes processed by the machine
		snowflake.clear();

		for (int i = 0; i < n; i++)
		{
			cin >> num;
			
			if (snowflake.count(num) == false) {
				//cout << "*" << num << " count = " << snowflake.count(num) << endl;
				//cnt = 1;
				//snowflake.clear();
				snowflake[num] = i;
			}
/*
			else 
			{
				cnt++;
				if (max < cnt)
					max = cnt;
			}*/
			//snowflake[num] = i;fszhdiyuop
			//cout << "*" << max << endl;
		}
		cout << snowflake.size() << endl;
		
	}
	return 0;
}