//UVa11572 : Darien Cortez : hastyhooligan

#include <iostream>
#include <map>

using namespace std;

int main()
{
    int t, n;
    int num;
    map<int, int> snowflake;//snowflake identifier
    cin>>t;//number of test cases
    
    while(t--)
    {
        int cnt = 0;
        cin >> n;//number of snowflakes processed by the machine
        snowflake.clear();
        
        for (int i=0; i<n; i++)
        {
            cin >> num;
            snowflake[i] = num;
            
            if(snowflake.count(num)>0)
                cnt++;
        }
        cout << n - cnt <<endl;
    }
    
	return 0;
}