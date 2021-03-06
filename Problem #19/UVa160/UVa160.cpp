//UVa160 : Darien Cortez : hastyhooligan

#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

vector<int>Prime(100);//vector to hold up to 100 prime numbers
int num = 0;//acts as index for the Prime vector

int main()
{
    vector<bool> notPrime(100, false);//initialize all values as a non prime number

    Prime[num++] = 2;//sets 2 as the the first prime number in Prime
    for(int i = 3; i < 100; i += 2)
    {
    	if(notPrime[i] == false)//if current number is prime do the following
    	{
    		Prime[num++] = i;//increment num and store next prime number
    		for(int j = 3; i*j < 100; j += 2)
    			notPrime[i*j] = true;//loops through and sets multiples of the prime number to true
    	}
    }
    
	int N;//number to find the factorial of
	while(cin >> N)
	{
		vector<int> storePrime(100,0);//stores prime factorials
		int tmp, length = num, cnt = 0;

	    if(N == 0)
	        break;
		
		//loops through numbers less than N
    	for(int i = 2; i <= N; i++)
    	{
    		tmp = i;//sets prime numbers to a temporary variable
			for (int j = 0; j < num && tmp != 1; j++)
			{
				//keeps track of prime number factorials in N
				while (tmp % Prime[j] == 0)
				{
					tmp /= Prime[j];
					storePrime[j]++;
				}
			}
    	}

    	cout << setw(3) << N << "! =";

    	while(storePrime[length] == 0)
    	    length--;//length is the number of prime numbers in Prime
    	    
    	for(int i = 0; i <= length; i++)
    	{
    		cnt++;//counter for the amount of numbers on each line
    		if(cnt > 15)
    		{
    		    cnt -= 15;
    		    cout << "\n      ";//indents 6 spaces
    		}
    		cout << setw(3) << storePrime[i];
    	}
    	cout << "\n";
	}
    return 0;
}

