/* 11727_CostCutting.cpp : Darien Cortez
   Programming Techniques
*/

#include "iostream"
using namespace std;


int main()
{
	/*T = test cases
	  a = first person
	  b = second person
	  c = third person
	*/
	int T, a, b, c;

	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> a;
		cin >> b;
		cin >> c;

		if (a > b && a < c || a > c && a < b)
			cout << "Case " << (i + 1) << ": " << a << endl;
		else if
			(a < b && b < c || c < b && b < a)
			cout << "Case " << (i + 1) << ": " << b << endl;
		else
			cout << "Case " << (i + 1) << ": " << c << endl;
	}
    return 0;
}

