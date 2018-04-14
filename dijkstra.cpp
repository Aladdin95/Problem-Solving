#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>

using namespace std;

struct edge
{
	edge(): destination(-1) , weight (-1){}
	int destination;
	int weight;
};

vector<int> dist;

bool waytosort(int lhs, int rhs)
{
	return dist[lhs] > dist[rhs];
}


int distance(vector<list<edge> > &adj, int s, int t) {

	dist = vector<int>(adj.size(),-1);

	vector<int>vertices;

	dist[s]=0;
	vertices.push_back(s);
	make_heap(vertices.begin(),vertices.end(),waytosort);
	bool flag = false;
	while(vertices.size())
	{
		if(flag) 
		{
			make_heap(vertices.begin(),vertices.end(),waytosort);
			flag = false;
		}

		pop_heap(vertices.begin(),vertices.end(),waytosort);
		//sort(vertices.begin(),vertices.end(),waytosort);
		int v = vertices.back();
		vertices.pop_back();
		for(auto i = adj[v].begin() ; i!= adj[v].end() ; ++i)
		{
			edge child = *i;
			if(dist[child.destination]==-1)
			{
				dist[child.destination]=dist[v]+child.weight;
				vertices.push_back(child.destination);
				if(!flag)push_heap(vertices.begin(),vertices.end(),waytosort);
			}
			else if(dist[child.destination]>dist[v]+child.weight)
			{
				dist[child.destination]=dist[v]+child.weight;
				flag=true;
			}
		}
	}
	return dist[t];
}


int main() {
	int n, m;
	cin >> n >> m;
	vector<list<edge> > adj(n);
	for (int i = 0; i < m; i++)
	{
		int x;
		edge temp;
		cin >> x >> temp.destination >> temp.weight;
		temp.destination--;
		adj[x - 1].push_back(temp);
	}
	int s, t;
	cin >> s >> t;
	s--, t--;
	cout << distance(adj, s, t);
}