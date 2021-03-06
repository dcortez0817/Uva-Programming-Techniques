// UVa10016_Squarelotron.cpp : Darien Cortez : hastyhooligan

#include <iostream>
#include <vector>

using namespace std;

void UpsideDown(vector<vector <char>> &, int, int);
void LeftRight(vector<vector <char>> &, int, int);
void MainDiagonal(vector<vector <char>> &, int, int);
void MainInverseDiagonal(vector<vector <char>> &, int, int);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int M, N, T, C, cnt = 0;

	cin >> M;
	while (cnt < M)//number of different cases to process
	{
		cin >> N;//size of matrix
		vector<vector <char>> mat(N, vector<char>(N));

		for (int r = 0; r < N; r++) {
			for (int c = 0; c < N; c++)
			{
				cin >> mat[r][c];
			}
		}

		int numR;//number of rings
		if (N % 2 == 0)
			numR = N / 2;
		else
			numR = N / 2 + 1;

		for (int R = 0; R < numR; R++)
		{
			cin >> T;//number of moves
			for (int i = 0; i < T; i++)
			{
				cin >> C;//C - case or which move to perform
				switch (C)
				{
				case 1:
					UpsideDown(mat, R, N);
					break;
				case 2:
					LeftRight(mat, R, N);
					break;
				case 3:
					MainDiagonal(mat, R, N);
					break;
				case 4:
					MainInverseDiagonal(mat, R, N);
					break;

				}
			}
		}

		for (int r = 0; r < N; r++) {
			for (int c = 0; c < N; c++)
			{
				if (c > 0)
					cout << ' ';
				cout << mat[r][c];
			}
			cout << endl;
		}

		cnt++;
	}
	return 0;
}

void UpsideDown(vector<vector <char>> &Sq, int R, int size)
{
	for (int i = R; i <= size - R - 1; i++)
		swap(Sq[R][i], Sq[size - R - 1][i]);

	for (int i = R + 1; (i << 1) < size - 1; i++)
	{
		int num = size - i - 1;
		swap(Sq[i][R], Sq[num][R]);
		swap(Sq[i][size - R - 1], Sq[num][size - R - 1]);
	}
}

void LeftRight(vector<vector <char>> &Sq, int R, int size)
{
	for (int i = R; i <= size - R - 1; i++)
		swap(Sq[i][R], Sq[i][size - R - 1]);

	for (int i = R + 1; (i << 1) < size - 1; i++)
	{
		int num = size - i - 1;
		swap(Sq[R][i], Sq[R][num]);
		swap(Sq[size - R - 1][i], Sq[size - R - 1][num]);
	}
}

void MainDiagonal(vector<vector <char>> &Sq, int R, int size)
{
	for (int i = R + 1; i <= size - R - 1; i++)
	{
		swap(Sq[R][i], Sq[i][R]);
		swap(Sq[size - R - 1][i], Sq[i][size - R - 1]);
	}
}

void MainInverseDiagonal(vector<vector <char>> &Sq, int R, int size)
{
	for (int i = size - R - 2, n = R + 1; i >= R; i--, n++)
	{
		swap(Sq[R][i], Sq[n][size - R - 1]);
		swap(Sq[n][R], Sq[size - R - 1][i]);
	}
}
