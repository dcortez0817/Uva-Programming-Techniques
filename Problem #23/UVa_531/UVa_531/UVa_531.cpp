// UVa_531.cpp : Darien Cortez : hastyhooligan

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
	string text;//text entered by the user
	vector<string> t1, t2;//first text and second text

	while (cin >> text)//gets text from user
	{
		t1.push_back(text);
		while (cin >> text && text != " " && text != "#")
		{
			t1.push_back(text);//gets the first text
		}
		
		while (cin >> text && text != " " && text != "#")
		{
			t2.push_back(text);//gets the second text
		}

        //2d vectors to store movement instructions and word counter
		vector<vector<int>> c(t1.size(), vector<int>(t2.size()));
		vector<vector<char>> b(t1.size(), vector<char>(t2.size()));
		
		for (int i = 1; i < t1.size(); i++)
		{
			for (int j = 1; j < t2.size(); j++)
			{
				if (t1[i] == t2[j])
				{
					c[i][j] = c[i - 1][j - 1] + 1;
					b[i][j] = 'd';//diagonal left arrow
				}

				else if (c[i - 1][j] >= c[i][j - 1])
				{
					c[i][j] = c[i - 1][j];
					b[i][j] = 'u';//up arrow
				}

				else
				{
					c[i][j] = c[i][j - 1];
					b[i][j] = 'l';//left arrow
				}
			}
		}

		int x = t1.size()-1, y = t2.size()-1;
        string lcs = "";
        while (c[x][y] != 0)//doesn't read from the zeroed out indices
        {
        	if (b[x][y] == 'd')//go diagonal
        	{
        		lcs = t1[x] + " " + lcs;
        			
        		x--;
        		y--;
        	}
        	
        	else if (b[x][y] == 'u')//go up
        		x--;
        	
        	else//go left
        		y--;
        }
		cout << lcs << endl;
	}

	return 0;
}