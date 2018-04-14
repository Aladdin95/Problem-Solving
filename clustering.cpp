#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <iomanip>

using namespace std;

const double inf = numeric_limits<double>::max();

struct edge
{
	edge():source(0){}
	edge(int x,int y,double z): source(x),destination(y),weight(z){}
	int source;
	int destination;
	double weight;
};

bool waytosort(edge lhs, edge rhs)
{
	return lhs.weight < rhs.weight;
}


double clustering(vector<int> x, vector<int> y, int kk) {

	double result = 0;

	vector<edge> adj ( x.size()*(x.size()-1) );
	
	vector<int> disjoint (x.size());
	for(int i=0 ;i < disjoint.size() ; ++i)disjoint[i]=i;
	
	int k=0;
	for (int i = 0; i < x.size(); i++)
	{
		for (int j = 0; j < x.size(); j++)
		{
			if(i==j)continue;
			double temp= sqrt ( pow((x[i]-x[j]),2) + pow((y[i]-y[j]),2) );
			adj[k]=edge(i,j,temp);
			k++;
		}
	}

	sort(adj.begin(),adj.end(),waytosort);

	int i,n;
	for (i=0,n=0; n < x.size()-kk+1 && i < adj.size(); i++)
	{		
		int set1;
		for(set1 = disjoint[adj[i].source] ; disjoint[set1]!=set1 ; set1=disjoint[set1]);

		int set2;
		for(set2 = disjoint[adj[i].destination] ; disjoint[set2]!=set2 ; set2=disjoint[set2]);

		if(set1==set2)continue;

		disjoint[set1]=disjoint[set2];

		n++;
	}

	return adj[i].weight;
} 


int main() {
	size_t n;
	int k;
	cin >> n;
	vector<int> x(n), y(n);
	for (size_t i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
	}
	cin >> k;
	cout << setprecision(10) << clustering(x, y, k) << endl;
}
