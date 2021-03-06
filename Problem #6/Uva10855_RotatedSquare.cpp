// Uva10855_RotatedSquare.cpp : Darien Cortez : hastyhooligan
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void rotate(int);
int found(int, int);

int main()
{
	int N, n, f; //w-z rotation degrees
	while (cin >> N && cin >> n)
	{
		vector<vector<char>> sq;//initialize 2D vector for N
		vector<vector<char>> sq1;//initialize 2D vector for n

		for (int r = 0; r < N; r++){
			for (int c = 0; c < N; c++)
				cin >> sq[r][c];
		}

		for (int r = 0; r < n; r++) {
			for (int c = 0; c < n; c++)
				cin >> sq1[r][c];
		}

		for(int k=0; k<N; k++)
			scanf("%s", sq[N][N])


		return 0;
}

	int found(int N, int n)
	{
		int l = 0; //counts the number of matrices of sq[n][n] inside sq1[N][N]
		int cnt = 0; //keeps track of characters that are found

		for (int r = 0; r < N; r++)
		{
			for (int c = 0; c < N; c++) {

				if (r + n <= N && c + n <= N) 
				{
					for (int i = 0; i < n; i++) {
						for (int j = 0; j < n; j++) {
							if (sq[r + i][c + j] == sq1[i][j])
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

	void rotate(int size) //rotates 90 degrees
	{
		for (int r = 0; r < size; r++){
			for (int c = 0; c < size; c++)
				m[r][c] = sq1[size - c - 1][r];
		}

		for (int r = 0; r < size; r++) {
			for (int c = 0; c < n; c++)
				sq1[r][c] = m[r][c];
		}
	}
