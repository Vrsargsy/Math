#include <vector>
#include <queue>
#include <iostream>

using namespace std;

/* void	bfs_list_distance(const vector<vector<int> >& graph, int start_vertex) // modified bfs without check from a -> b just from 0 -> b
{
	vector<int> used(graph.size(), 0);
	used[start_vertex] = 1;
	queue<int> q;
	q.push(start_vertex);
	vector<int> distance(graph.size(), 0);
	while(!q.empty())
	{
		int current_vertex = q.front();
		q.pop();
		cout << current_vertex + 1 << " ";
		for(int i = 0; i < graph[current_vertex].size(); ++i)
		{
			int adjacent_vertex = graph[current_vertex][i];
			if(!used[adjacent_vertex])
			{
				q.push(adjacent_vertex);
				distance[adjacent_vertex] = distance[current_vertex] + 1;
				used[adjacent_vertex] = 1;  
			}
		}
	}
		cout << endl;
	for(int i = 0; i < distance.size(); ++i)
	{
		cout << i + 1 << " " << distance[i] << endl;
	}
} */

void	bfs_list_distance(const vector<vector<int> >& graph, int start_vertex)
{
	vector<int> used(graph.size(), -1);
	used[start_vertex] = 0;
	queue<int> q;
	q.push(start_vertex);
	vector<int> distance(graph.size(), 0);
	while(!q.empty())
	{
		int current_vertex = q.front();
		q.pop();
		cout << current_vertex + 1 << " ";
		for(int i = 0; i < graph[current_vertex].size(); ++i)
		{
			int adjacent_vertex = graph[current_vertex][i];
			if(used[adjacent_vertex] == -1)
			{
				q.push(adjacent_vertex);
				distance[adjacent_vertex] = distance[current_vertex] + 1;
				used[adjacent_vertex] = used[current_vertex] + 1;  
			}
		}
	}
		cout << endl;
	for(int i = 0; i < distance.size(); ++i)
	{
		cout << i + 1 << " " << used[i] << endl;
	}
}

int main()
{
	vector<vector<int> > graph {
		{1, 2},
		{0, 3, 6},
		{0, 3},
		{1, 2, 4, 5, 6},
		{3, 7},
		{3, 7},
		{1, 3, 7},
		{4, 5, 6, 8},
		{7}
	};

	bfs_list_distance(graph, 1); // O (n * n + m)
}