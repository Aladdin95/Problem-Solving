#include <iostream>
#include <vector>
#include <list>
#include <queue>

using namespace std;

int distance(vector<list<int> > &adj, int s, int t)
{
	queue<int> myq;
	vector<int> distances(adj.size(),-1);
	
	distances[s]=0;
	if(s==t)return 0;
	myq.push(s);

	while(!myq.empty())
	{
		int v = myq.front();
		myq.pop();
		for(auto i = adj[v].begin() ; i!= adj[v].end() ; ++i)
		{
			if(distances[*i]!=-1)continue;
			distances[*i]=distances[v]+1;
			if(*i==t)return distances[t];
			myq.push(*i);
		}
	}
	return -1;
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
	int s, t;
	cin >> s >> t;
	s--, t--;
	cout << distance(adj, s, t);
}