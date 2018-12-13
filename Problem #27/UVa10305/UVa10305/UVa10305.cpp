// UVa10305.cpp : Darien Cortez : hastyhooligan

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<vector<int>> adjList;
stack<int> stk;
vector<bool> visited;

void dfs(int x) 
{
	if (visited[x])
		return;//backtrack if its already been visisted
	visited[x] = true;
	for (int i = 0; i < (int)adjList[x].size(); i++) {
		dfs(adjList[x][i]);
	}
	stk.push(x);
}

int main()
{
	int n, m;
	while (cin >> n >> m)
	{
	    adjList.clear();
	    adjList.resize(n+1);
		visited.assign(n, false);
		
		for (int k = 0; k < m; k++)
		{
			int i, j;
			cin >> i >> j;
			adjList[i].push_back(j);
		}

		for (int i = 0; i < visited.size(); i++)
		{
		    visited[i] = false;
	    }
		
		for (int i = 1; i <= n; i++)
		{
			if (!visited[i])
				dfs(i);
		}
		
		while (!stk.empty())
		{
			cout << stk.top() << " ";
			stk.pop();
		}
		cout << endl;
	}
	return 0;
}