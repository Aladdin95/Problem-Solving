#include <iostream>
#include <vector>
#include <list>

using namespace std;

int explore(vector<list<int> > &adj,vector<bool> &flag ,int &v,int &y)
{
	if(v==y) return 1;
	flag[v]=true;
	for(auto i = adj[v].begin() ; i != adj[v].end() ; i++)
	{
		if(!flag[*i])
		{
			if(explore(adj,flag,*i,y)) return 1;
		}
	}
	return 0;
}

int reach(vector<list<int> > &adj, int x, int y) {
	
	vector<bool> flag(adj.size(),false);
	return explore(adj,flag,x,y);
}

int main() 
{
	size_t n, m;
	cin >> n >> m;
	vector<list<int>> adj(n);

	for (size_t i = 0; i < m; ++i)
	{
		int x, y;
		cin >> x >> y;
		adj[x - 1].push_back(y - 1);
		adj[y - 1].push_back(x - 1);
	}
	int x, y;
	cin >> x >> y;
	cout << reach(adj, x - 1, y - 1);

	return 0;
}
