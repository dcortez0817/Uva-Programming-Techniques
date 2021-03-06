// UVa280.cpp : Darien Cortez : hastyhooligan

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class AdjancencyVectorGraph
{
public:
	//num Vec - number of vectors in a directed graph
	//start - starting vertex
	//edges - series of edges from the starting vertex
	int numVec, start, edges;

	vector<vector<bool>> reachable;//matrix storing reachable vertices 

	void initializeAdjMatrix()
	{
		for (int i = 0; i < numVec; i++)
		{
			for (int j = 0; j < numVec; j++)
			{
				reachable[i][j] = false;//sets all values in adjacency matrix to zero
			}
		}

		while (cin >> start && start != 0)
		{
			while (cin >> edges && edges != 0)
			{
				reachable[start-1][edges-1] = true;//set reachable vertices to true
			}
		}
	}
};

int main()
{
	int n, numInv, Inv;
	
	while (cin >> n)//number of vertices in the graph
	{
		AdjancencyVectorGraph matrix;
		vector<vector<bool>> reach(n, vector<bool>(n));

		matrix.reachable = reach;
		matrix.numVec = n;

		matrix.initializeAdjMatrix();
		reach = matrix.reachable;

		for (int k = 0; k < n; k++)
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					reach[i][j] = |= reachable[i][k] && reachable[k][j];

		cin >> numInv;//number of vertices to investigate
		for (int x = 0; x < numInv; x++)
		{
			int cnt = 0;//keeps track of inaccessible vertex numbers

			cin >> Inv;//vertex to investigate
			for (int i = 0; i < n; i++)
			{
				if (reach[Inv - 1][i] == false)
					cnt++;
			}
			
			cout << cnt;
			for (int j = 0; j < n; j++)
			{
				if (reach[Inv - 1][j] == false)
					cout << " " << j + 1;
			}
			cout << endl;[]
		}
	}
	
	return 0;
}