//UVa355 : Darien Cortez : hastyhooligan

#include <iostream>

using namespace std;

int main()
{
	int b1, b2;//b1 is current base and b2 is base we want ti convert to
	char num[10];//actual value of current base (b1)

	while (cin >> b1 && cin >> b2 && cin >> num)
	{
		bool invalid = false;//acts as bool value, set to false
		long long dec = 0, base = 1;//64 bits for dec and base

		for (int i = 0; num[i]; i++)
		{
			dec *= b1;//multiplies base by each bit value
			//checks if the actual bit value is between 0-9
			if (num[i] >= '0' && num[i] <= '9')
			{
				//if bit value is greater than base number, valid = 1 (false)
				if (num[i] - '0' >= b1)
					invalid = true;
				else
					dec += num[i] - '0';//else add onto decimal number
			}
			else
			{
				//checks if the actual bit value is above 10
				if (num[i] - 'A' + 10 >= b1)//same if as above (comparing value to base)
					invalid = true;
				else
					dec += (num[i] - 'A' + 10);//adds onto decimal value of base number
			}
		}

		//pronts message if actual value of b1 is invalid
		if (invalid)
			cout << num << " is an illegal base " << b1 << " number\n";

		//actual value is valid
		else
		{
			//initializes actual value for b2 as nNum (new num) in a vector
			long long nNum[20] = {}, cnt = -1;
			//conversion from decimal numbers to the base number
			while (dec)
			{
				//count starts at -1 to get rid of zeros out front
				nNum[++cnt] = dec % b2;//stores remainder in vector
				dec /= b2;//divides decimal number by base
			}

			if (cnt < 0)
				cnt = 0;

			cout << num << " base " << b1 << " = ";

			while (cnt >= 0)
			{
				//adds ascii number '0' for bits under 9
				if (nNum[cnt] <= 9)
					nNum[cnt] + '0';

				//adds asciinumber 'A' for bits between 10-15 (A-E)
				else
					nNum[cnt] - 10 + 'A';

				cout << nNum[cnt];
				cnt--;
			}

			cout << " base " << b2 << endl;
		}
	}
	return 0;
}