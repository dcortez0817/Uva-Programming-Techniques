// UVA10336 - Rank the Languages.cpp : Darien Cortez : hastyhooligan

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void CleanBlob(int, int, vector<string> &, char);
bool comp(pair<char, int>, pair<char, int>);

int main()
{
	int N, H, W;
	cin >> N;//Test cases

	for (int n = 1; n <= N; n++)
	{
		cin >> H >> W;
		H += 2;//height
		W += 2;//width

		//set a border of '-' characters for the map
		vector<string> lang(H);
		lang[0] = string(W, '-');
		lang[H - 1] = string(W, '-');

		for (int i = 1; i < H - 1; i++)
		{
			cin >> lang[i];
			lang[i] = '-' + lang[i] + '-';
		}

		cout << "World #" << n << endl;
		vector<pair<char, int>> T(26);//alot 26 pairs for possible languages (alphabet)
		int letter = 97;//ascii letter

		//store the letters of the alphabet in a vector of pairs
		for (int l = 0; l < 26; l++)
		{
			T[l].first = (char)letter;//converts to lowercase letters
			T[l].second = 0;//sets # of letters in the map to 0
			letter++;
		}

		//loops through map and updates characters
		for (int i = 1; i < H - 1; i++) {
			for (int j = 1; j < W - 1; j++)
			{
				char ch = lang[i][j];
				if (ch != '-')
				{
					CleanBlob(i, j, lang, ch);
					T[ch-97].second += 1;//increases # of times letter is in map
				}
			}
		}

		//sorts the map based on the languages spoken
		sort(T.begin(), T.end(), comp);

		for(int num = 0; num < 26; num++)
		{
			if(T[num].second != 0)
				cout << T[num].first << ": " << T[num].second << endl;
		}
	}

	return 0;
}

void CleanBlob(int r, int c, vector<string>&lang, char ch)
{
	if (lang[r][c] != ch)
		return;

	//change searched characters to '-'
	lang[r][c] = '-';
	CleanBlob(r + 1, c, lang, ch);
	CleanBlob(r - 1, c, lang, ch);
	CleanBlob(r, c + 1, lang, ch);
	CleanBlob(r, c - 1, lang, ch);
}

bool comp(pair<char, int> a, pair<char, int> b)
{
	if (a.second == b.second)
		return a.first < b.first;

	else
		return a.second > b.second;
}

