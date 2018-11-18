// 11799_HorrorDash.cpp : Darien Cortez: hastyhooligan.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	//N = students in scary costumes
	//T = test cases
	//c = speed of students in scary costumes
	//s = required speed of clowns


	int T, N, c, s;

	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> N;
		vector<int> H(N);

		for (c = 0; c < N; c++)
		{
			cin >> H[c];
		}

		sort(H.begin(), H.end());
		s = H[N - 1];

		cout << "Case " << (i + 1) << ": " << s << endl;
	}

	system("pause");
	return 0;
}