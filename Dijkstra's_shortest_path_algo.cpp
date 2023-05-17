#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<int>	dijkstra(const vector<vector<pair<int,int>> >& graph, int start_vertex)
{
	const int Inf = 10000000;
	vector<int> dist(graph.size(), Inf);
	dist[start_vertex] = 0;
	set<pair<int,int>> s;
	// set for sort {dist[v], v};
	s.insert({ 0,start_vertex });

	while(!s.empty()) // O(m * log(n))
	{
		int current_vertex = s.begin()->second;
		s.erase(s.begin());
		for(int i = 0; i < graph[current_vertex].size(); ++i)
		{
			int adjacent_vertex = graph[current_vertex][i].first;
			int cost = graph[current_vertex][i].second;
			if(dist[current_vertex] + cost < dist[adjacent_vertex])
			{
				s.erase({ dist[adjacent_vertex], adjacent_vertex });
				dist[adjacent_vertex] = dist[current_vertex] + cost;
				s.insert({ dist[adjacent_vertex], adjacent_vertex });
			}
		}
	}
	return dist;
}

int main()
{
	vector<vector<pair<int,int>>> graph{
		{{1, 10}, {5, 5}},
		{{0, 10}, {2, 1}},
		{{1, 1}, {3, 5},{5, 7},{6, 10}},
		{{2, 5}, {4, 1}},
		{{3, 1}, {6, 2}},
		{{0, 5}, {2, 7}, {6, 100}, {7, 3}},
		{{2, 10},{4, 2}, {5, 100}, {7, 8}, {8, 100}},
		{{5, 3}, {6, 8}, {9, 1}},
		{{6, 100}, {9, 1}},
		{{7, 1}, {8, 1}},                   
	};

	vector<int> dist = dijkstra(graph, 0);
	for (int i = 0; i < dist.size(); ++i)
	{
		cout << "To vertex: " << i + 1 << ": " << dist[i] << " steps" << endl;
	}
}