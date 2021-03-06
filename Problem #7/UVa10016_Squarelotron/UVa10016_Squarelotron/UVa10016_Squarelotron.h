// UVa10016_Squarelotron.cpp : Darien Cortez : hastyhooligan

#include <iostream>
#include <vector>

using namespace std;

void UpsideDown(vector<vector <char>> &, int, int);
void LeftRight(vector<vector <char>> &, int, int);
void MainDiagonal(vector<vector <char>> &, int);
void MainInverseDiagonal(vector<vector <char>> &, int, int);

int LR; //lower right hand corners

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

		for (int R = 0; R < numR; R++) //R = ring number
		{
		    LR = N - R - 1;//set lowerRight equal to the end of the current ring
		    
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
					MainDiagonal(mat, R);
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

//UL = R in all the functions
//size-R-1 allows you to convert the rows and columns between UL and LR
void UpsideDown(vector<vector <char>> &Sq, int UL, int size)
{
    //swaps top and bottom of current ring
	for (int r = UL; r <= LR; r++)
		swap(Sq[UL][r], Sq[LR][r]);

    //swaps indexes between UL and LR of current ring
	for (int c = UL + 1; c < size -  c - 1; c++)
	{
		swap(Sq[c][UL], Sq[size - c - 1][UL]);
		swap(Sq[c][size - c - 1], Sq[size - c - 1][LR]);
	}
}

void LeftRight(vector<vector <char>> &Sq, int UL, int size)
{
    //swaps left and right of current ring
	for (int r = UL; r <= LR; r++)
		swap(Sq[r][UL], Sq[r][LR]);

    //swaps indexes between UL and LR of current ring
	for (int c = UL + 1; c < size -  c - 1; c++)
	{
		swap(Sq[UL][c], Sq[UL][size - c - 1]);
		swap(Sq[size - c - 1][c], Sq[LR][size - c - 1]);
	}
	
}

void MainDiagonal(vector<vector <char>> &Sq, int UL)
{
	for (int r = UL + 1; r <= LR; r++) // swaps left col and bottom row of current ring
	    swap(Sq[r][UL], Sq[UL][r]);
       
    for (int c = UL + 1; c < LR; c++) //swaps bottom row and right col of current ring
        swap(Sq[LR][c], Sq[c][LR]);
}

void MainInverseDiagonal(vector<vector <char>> &Sq, int UL, int size)
{
	for (int r = UL; r < LR; r++) // Swaps top row and right column of current ring
	    swap(Sq[UL][r], Sq[size -  r - 1][LR]);
						
	for (int c = UL + 1; c <= LR; c++) // Swaps left column and bottom row of current ring
	    swap(Sq[c][UL], Sq[LR][size -  c - 1]);
}

