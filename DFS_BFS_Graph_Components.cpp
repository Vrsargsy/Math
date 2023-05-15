#include<iostream>
#include<vector>

using namespace std;
// DFS algorithm using graph with components
//the same with DFS_Matrix, BFS_list, BFS_Matrix

void dfs_list(const vector<vector<int>>& graph,
                vector<int>& used,
                int current_vertex)
{
    cout << current_vertex + 1 << " ";
    used[current_vertex] = 1;
    for (int i = 0; i < graph[current_vertex].size(); ++i)
    {
        int adjacent_vertex = graph[current_vertex][i];
        if (used[adjacent_vertex] != 1)
        {
            dfs_list(graph, used, adjacent_vertex);
        }
    }
}

int main()
{
	vector<vector<int>> graph {
		{4,5},
		{3},
		{3},
		{1,2,9},
		{0},
		{0},
		{},
		{8},
		{7},
		{3}
	};

	vector<int> used(graph.size(), 0);
	for(int i = 0; i < graph.size(); ++i)
	{
		if (!used[i])
		{
			dfs_list(graph,used,i);
			cout << endl;
		}
	}
}