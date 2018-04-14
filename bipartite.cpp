#include <iostream>
#include <vector>
#include <list>
#include <queue>

using namespace std;

bool bfs(vector<list<int> > &adj,vector<int>&distance,int s)
{
	queue<int> myq;

	distance[s]=0;
	myq.push(s);
	while(!myq.empty())
	{
		int v = myq.front();
		myq.pop();
		for(auto i = adj[v].begin() ; i!= adj[v].end() ; ++i)
		{
			if(distance[*i]!=-1)
			{
				if(distance[v]==distance[*i])return true;
				continue;
			}
			distance[*i]=distance[v]+1;
			myq.push(*i);
		}
	}
	return false;
}

int bipartite(vector<list<int> > &adj) 
{
	vector<int>distance(adj.size(),-1);

	for(int i = 0 ; i< adj.size() ; ++i)
	{
		if(distance[i]==-1) 
		{
			if(bfs(adj,distance,i)) return 0;
		}
	}
	return 1;
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<list<int> > adj(n);
	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		adj[x - 1].push_back(y - 1);
		adj[y - 1].push_back(x - 1);
	}
	cout << bipartite(adj);
}