// UVa10684 : Darien Cortez : hastyhooligan 

#include <iostream>

using namespace std;

int main()
{
	int N, n;

	while (cin >> N && N != 0)
	{
		int mx = 0, temp = 0;

		for (int i = 0; i < N; i++)
		{
			cin >> n;
			temp += n;
			if (temp > mx)
				mx = temp;

			if(temp < 0)
				temp = 0;
		}

		if (mx > 0)
			cout << "The maximum winning streak is " << mx << ".\n";

		else
			cout << "Losing streak.\n";
	}

	return 0;
}