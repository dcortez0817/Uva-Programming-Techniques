// Uva836.cpp : Darien Cortez : hastyhooligan

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<vector<int>> A;
	int T, num; //test case
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		while (cin >> num)
		{
			for (int i = 0; i < 25; i++)
			{
				for (int j = 0; j < 25; j++)
				{
					A[i][j] = num;
					cout << A[i][j] << " ";
				}
				cout << endl;
			}
		}
	}

	return 0;
}
