#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
#include <limits>

using namespace std;

const long long inf = numeric_limits<long long>::max();

struct edge
{
	edge(): destination(-1) , weight (-1){}
	int destination;
	int weight;
};


void shortest_paths(vector<list<edge> >&adj, int s, vector<long long> &distance,vector<bool> reachable, vector<bool> &shortest) 
{
	queue<int> bfs_queue ;
	distance[s]=0;
	reachable[s]=true;

	for(int k=1 ; k<adj.size() ; ++k){
		for(int i=0 ; i<adj.size() ; ++i){
			for(auto child : adj[i]){
				if(reachable[i] && distance[child.destination]>distance[i]+child.weight)
				{
					distance[child.destination]=distance[i]+child.weight;
					reachable[child.destination]=true;
				}}}}

	for(int i=0 ; i<adj.size() ; ++i){
		for(auto child : adj[i]){
			if(reachable[i] && distance[child.destination]>distance[i]+child.weight&&shortest[i]==true)
			{
				shortest[i]=false;
				bfs_queue.push(i);
			}}}
		
	while(bfs_queue.size())
	{
		int v = bfs_queue.front();
		bfs_queue.pop();
		for(auto i : adj[v])
		{
			if(shortest[i.destination])
			{
				shortest[i.destination]=false;
				bfs_queue.push(i.destination);
			}
		}
	}
}


int main() {
	int n, m, s;
	std::cin >> n >> m;
	vector<list<edge> > adj(n);
	for (int i = 0; i < m; i++) 
	{
		int x;
		edge temp;
		std::cin >> x >> temp.destination >> temp.weight;
		temp.destination--;
		adj[x - 1].push_back(temp);
	}
	std::cin >> s;
	s--;
	vector<long long> distance(n,inf);
	vector<bool> shortest(n, true);
	vector<bool> reachable(n, false);

	shortest_paths(adj, s, distance,reachable, shortest);

	for (int i = 0; i < n; i++) 
	{
		if (distance[i]==inf) {
			std::cout << "*\n";
		} else if (!shortest[i]) {
			std::cout << "-\n";
		} else {
			std::cout << distance[i] << "\n";
		}
	}
}