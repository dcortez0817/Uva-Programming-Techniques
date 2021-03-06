// Uva10855_RotatedSquare.cpp : Darien Cortez : hastyhooligan

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void rotate(vector<vector<char>> &, int);
int found(vector<vector<char>>, vector<vector<char>>, int, int);

int main()
{
	int N, n;
	while (cin >> N && cin >> n)
	{
		vector<vector<char>> sq(N, vector<char >(N));//initialize 2D vector for N
		vector<vector<char>> sq1(n, vector<char >(n));//initialize 2D vector for n

		for (int r = 0; r < N; r++) {
			for (int c = 0; c < N; c++)
				cin >> sq[r][c];
		}

		for (int r = 0; r < n; r++) {
			for (int c = 0; c < n; c++)
				cin >> sq1[r][c];
		}

		if (N == 0 && n == 0)
			break;

		//print result
		for (int k = 0; k < 4; k++)
		{
			if (k)
				cout << ' ';

			cout << found(sq, sq1, N, n);
			rotate(sq1, n);
		}

		cout << '\n';
	}
	return 0;
}

int found(vector<vector<char>>  m1, vector<vector<char>>  m2, int N, int n)//finds matches
{
	int l = 0; //counts the number of matrices of sq[n][n] inside sq1[N][N]


	for (int r = 0; r < N; r++)
	{
		for (int c = 0; c < N; c++) {

			if (r + n <= N && c + n <= N)
			{
				int cnt = 0; //keeps track of characters that are found

				for (int i = 0; i < n; i++) {
					for (int j = 0; j < n; j++) {
						if (m1[r + i][c + j] == m2[i][j])
							cnt++;
					}
				}
				if (cnt == n * n)
					l++;
			}
		}
	}
	return l;
}

void rotate(vector<vector<char>> &m, int size) //rotates 90 degrees
{
	vector<vector<char>> temp(size, vector<char >(size));

	for (int r = 0; r < size; r++) {
		for (int c = 0; c < size; c++) {
			temp[r][c] = m[size - c - 1][r];
		}
	}

	for (int r = 0; r < size; r++) {
		for (int c = 0; c < size; c++) {
			m[r][c] = temp[r][c];
		}
	}
}