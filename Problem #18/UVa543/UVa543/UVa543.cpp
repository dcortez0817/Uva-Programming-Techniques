// UVa543.cpp : Darien Cortez : hastyhooligan

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n, a, b;//a & b = prime odd numbers

	while (cin >> n)//even integer between 6 and 1000000
	{
	    if(n == 0)
	        break;
	    
	    vector<bool> prime(n, true);//initializes all values to true
	    prime[0] = false;
	    prime[1] = false;

	    //sieve of Eratosthenes algorithm to find prime numbers
	    for (int i = 2; i < n; ++i)
	    {
	        for (int j = 2; i*j < n; ++j) 
 		        prime[i*j] = false;
	    }
	    
	    //loop through half of n to find the max prime values
	    for (a = 2; a <= (n/2); a++)
	    {
	        b = n-a;//subtract a from n to find prime value for b
			if (prime[a] && prime[b])//prints the sum if a and b are prime
			{ 
				cout << n << " = " << a << " + " << b << "\n";
				break; 
			} 
	    }
	}

	return 0;
}
