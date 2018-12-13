//11172_RelationalOperators: Darien Cortez: hastyhooligan

#include <iostream>

using namespace std;

int main()
{
    //T = test cases
    //a = first integer
    //b = second integer
    
    int T, a, b;
    
    cin >> T;
    for(int i=0; i<T; i++)
    {
        cin >> a;
        cin >> b;
        
        if(a == b)
            cout << "=" << endl;
        else if(a < b)
            cout << "<" << endl;
        else
            cout << ">" << endl;
    }

    return 0;
}