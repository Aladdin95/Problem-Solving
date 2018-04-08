#include <iostream>
#include <vector>
#include <list>

using namespace std;


void explore(vector<list<int> > &adj,vector<bool> &flag,int v)
{
	flag[v]=true;
	for(auto i = adj[v].begin() ; i != adj[v].end() ; i++)
	{
		if(!flag[*i])
		{
			explore(adj,flag,*i);
		}
	}
}

int number_of_components(vector<list<int> > &adj) {
	
	int res = 0;
	vector<bool> flag(adj.size(),false);

	for(int j = 0 ; j< adj.size(); j++)
	{
		if(!flag[j])
		{
			res++;
			explore(adj,flag,j);
		}
	}
	return res;
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
	cout << number_of_components(adj);

	return 0;
}
