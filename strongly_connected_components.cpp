#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void dfs_list_topo(const vector<vector<int>>& graph,
                vector<int>& used,
				vector<int>& order,
                int current_vertex)
{
    used[current_vertex] = 1;
    for (int i = 0; i < graph[current_vertex].size(); ++i)
    {
        int adjacent_vertex = graph[current_vertex][i];
        if (used[adjacent_vertex] != 1)
        {
            dfs_list_topo(graph, used, order, adjacent_vertex);
        }
    }
	order.push_back(current_vertex);
} 
void	dfs_reverse(const vector<vector<int>>& graph,
                vector<int>& used,
                vector<int>& component,
                int current_vertex)
{
	component.push_back(current_vertex);
    used[current_vertex] = 1;
    for (int i = 0; i < graph[current_vertex].size(); ++i)
    {
        int adjacent_vertex = graph[current_vertex][i];
        if (used[adjacent_vertex] != 1)
        {
            dfs_reverse(graph, used, component, adjacent_vertex);
        }
    }
}

int main()
{
	vector<vector<int> > graph {
		{2},
		{0, 2},
		{3, 4},
		{},
		{1, 8},
		{10},
		{5},
		{1, 5},
		{9},
		{8},
		{6, 7},
	};

	vector<int> used(graph.size());
	vector<int> order;

	for(int i = 0; i < graph.size(); ++i)
	{
		if (!used[i])
		{
			dfs_list_topo(graph, used, order, i);
		}
	}
	reverse(order.begin(),order.end());

	vector<vector<int> > reverse_graph(graph.size());
	for(int i = 0; i < graph.size(); ++i)
	{
		for(int j = 0; j < graph[i].size(); ++j)
		{
			//i -> graph[i][j] edge
			reverse_graph[graph[i][j]].push_back(i);
		}
	}
	used.assign(graph.size(), 0);

	for(int i = 0; i < order.size(); ++i)
	{
		if (!used[order[i]])
		{
			vector<int> component;
			dfs_reverse(reverse_graph, used,component, order[i]);
			sort(component.begin(), component.end());
			for(auto a : component)
			{
				cout << a + 1 << " ";
			}
			cout << endl;
		}
	}
}