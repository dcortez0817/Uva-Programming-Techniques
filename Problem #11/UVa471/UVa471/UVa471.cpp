// UVa471.cpp : Darien Cortez : hastyhooligan

#include <iostream>
#include <set>

using namespace std;


bool isUnique(long long);

int main()
{
	int T, cnt = 0;
	long long max = 9876543210;//maximum possible integer value with non matching digits
	long long N;//given integer represented as a string

	cin >> T; //test cases
	while (cnt < T)
	{
		cnt++;//counter

		if(cnt > 1)
			cout << "\n";//prints extra line between cases
		
		cin >> N;//given integer
		
		for (int i = 1; N*i <= max; i++) 
		{
			if (isUnique(i))//s2
			{
				if (isUnique(N*i))//s1
					cout << N * i << " / " << i << " = " << N << endl;
			}
		}
	}

	return 0;
}

bool isUnique(long long n)
{
	int m = 0;//acts as mod counter
	set<int> st;

	while (n != 0)
	{
		m++;
		st.insert(n % 10);//puts each individual bit in a set
		n /= 10;
	}

	if (st.size() == m)//sets don't repeat digits
		return true;
	else
		return false;
}