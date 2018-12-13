// UV10986.cpp : Darien Cortez : hastyhooligan

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> ii;//defines a pair called ii
typedef vector<int> vi;//defines a vector of ints caled vi
typedef vector<ii> vii;//defines a vector of a vector of pairs called vii

int main()
{
	int N, n, m, S, T, x, y, w;
	vector<vii> AdjList;

	cin >> N;//test cases
	for (int i = 1; i <= N; i++)
	{
		cin >> n;//# of servers
		cin >> m;//# of cables
		cin >> S;//starting messenger server
		cin >> T;//receiving messenger server

		// assigns blank vectors of pairs to AdjList
		AdjList.assign(n, vii());
		for (int j = 0; j < m; j++)
		{
			cin >> x;//server connected to y
			cin >> y;//server connected to x
			cin >> w;//latency in miliseconds
			AdjList[x].push_back(ii(y, w));
			AdjList[y].push_back(ii(x, w)); // if bi-directional
		}

		vi dist(n, 1000000);//sets every distance to the max latency
		dist[S] = 0;

		priority_queue< ii, vector<ii>, greater<ii> > pq;
		pq.push(ii(0, S));//sorts the pairs by increasing distance from S

		while (!pq.empty())
		{
			ii front = pq.top();//
			pq.pop();     //picks the shortest unvisited vertex
			int d = front.first, u = front.second;

			if (d > dist[u])//important for 'Lazy Deletion'
				continue;

			for (int j = 0; j < (int)AdjList[u].size(); j++)
			{
				ii v = AdjList[u][j];//all outgoing edges from u
				if (dist[u] + v.second < dist[v.first])
				{
					dist[v.first] = dist[u] + v.second;// relaxes edges from u to v
					pq.push(ii(dist[v.first], v.first));
				}
			}
		}

		if (dist[T] == 1000000)
			cout << "Case #" << i << ": " << "unreachable" << endl;
		else
			cout << "Case #" << i << ": " << dist[T] << endl;
	}

	return 0;
}