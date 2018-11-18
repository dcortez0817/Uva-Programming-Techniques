//UVa10295 : Darien Cortez : hastyhooligan

#include <iostream>
#include <map>//powerful for text proccessing

using namespace std;

int main()
{
    int m, n, value;//value represents the word's importance
    map<string, int> respon;//responsibility amount
    string word;//word with responsibility
    long int sum;
    
    cin >> m;//number of words in the Hay Point dictionary
    cin >> n;//number of job descriptions
    
    while(m--)
    {
        cin >> word;
        cin >> value;
        
        respon[word] = value;
    }
    
    while(n--)
    {
        sum = 0;
        while(cin >> word && word != ".")
            sum = sum + respon[word];
        cout << sum << endl;
    }

	return 0;
}