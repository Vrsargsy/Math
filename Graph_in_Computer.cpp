// How to create Graph in memory.

#include <iostream>
#include <vector>

using namespace std;

/*
 n	 m
 a1	b1
 a2 b2
 ...
 a(m) b(m)
*/

/* Graph

1 2
1 3
1 4
1 5
2 1
2 3
3 4
3 2
4 3
4 5
5 1
5 4
*/
void	list_of_edges()
{
	int n,m;
	cin >> n >> m;

	vector<pair<int, int> > edges(m);
	for(int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;
		edges[i] = { a, b };
	}
	cout << "List of edges" << endl;
	for(int i = 0; i < m; ++i)
		cout << edges[i].first << " " << edges[i].second << endl;
	cout << endl;
}

void	Adjacency_matrix()
{
	int n,m;
	cin >> n >> m;

	vector<vector<int> > matrix(n, vector<int>(n));
	for(int i = 1; i <= m; ++i)
	{
		int a,b;
		cin >> a >> b;

		// 1 <= a, b <= n for indexes
		--a, --b;
		matrix[a][b] = 1;
		matrix[b][a] = 1;
	}

	cout << "\nAdjacency matrix" << endl;

	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void	Adjacency_list()
{
	int n,m;
	cin >> n >> m;
	vector<vector<int> > matrix(n);
	for(int i = 0; i < m; ++i)
	{
		int a,b;
		cin >> a >> b;
		--a, --b;
		// non-orineted
		matrix[a].push_back(b);
		matrix[b].push_back(a);

		// oriented
		// matrix[a].push_back(b);
	}
	cout << "\nAdjacency list" << endl;

	for(int i = 0; i < n; ++i)
	{
		cout << i << ": ";
		for(int j = 0; j < matrix[i].size(); ++j)
		{
			cout << matrix[i][j] + 1<< " "; // + 1 just for indexes
		}
		cout << endl;
	}
	cout << endl;
}

int main()
{
	list_of_edges();
	Adjacency_matrix();
	Adjacency_list();
}