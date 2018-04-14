#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
#include <limits>

using namespace std;

const int inf = numeric_limits<int>::infinity();

struct edge
{
	edge(): destination(-1) , weight (-1){}
	int destination;
	int weight;
};

int negative_cycle(vector<list<edge> > &adj) 
{
	vector<int> dist(adj.size(),inf);

	dist[0]=0;

	for(int k=0 ; k<adj.size()-1 ; ++k)
	{
		for(int i=0 ; i<adj.size() ; ++i)
		{
			for(auto child : adj[i])
			{
				if(dist[child.destination]>dist[i]+child.weight)
				{
					dist[child.destination]=dist[i]+child.weight;
				}
			}
		}
	}

	for(int i=0 ; i<adj.size() ; ++i)
	{
		for(auto child : adj[i])
		{
			if(dist[child.destination]>dist[i]+child.weight)
			{
				return 1;
			}
		}
	}
	return 0;
}

int main() {
	int n, m;
	std::cin >> n >> m;
	vector<list<edge> > adj(n);
	for (int i = 0; i < m; i++) {
		int x;
		edge temp;
		std::cin >> x >> temp.destination >> temp.weight;
		temp.destination--;
		adj[x - 1].push_back(temp);
	}
	std::cout << negative_cycle(adj);
}