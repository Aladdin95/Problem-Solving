#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool howtosort(vector<int> x, vector<int> y)
{
	if(x[0]==y[0])return x[1]<y[1];
	return x[0]<y[0];
}

long long gridlandMetro(int n, int m, int k, vector < vector<int> > track) {

	if(k==0) return (long long)m*n;

	long long metro=0;

	sort(track.begin(),track.end(),howtosort);
	int temp[2]={track[0][1],track[0][2]};
	for(size_t i=0 ; i<k-1 ;++i)
	{
		if(track[i+1][0]>track[i][0] || track[i+1][1]>temp[1])
		{
			metro+= temp[1]-temp[0]+1;
			temp[0]=track[i+1][1];
			temp[1]=track[i+1][2];
		}
		else if(track[i+1][2]>temp[1])
		{
			temp[1]=track[i+1][2];
		}
	}
	metro+= temp[1]-temp[0]+1;

	return (long long)m*n-metro;
}

int main() {
    int n;
    int m;
    int k;
    cin >> n >> m >> k;

    vector< vector<int> > track(k,vector<int>(3));

    for(int track_i = 0;track_i < k;track_i++){
       for(int track_j = 0;track_j < 3;track_j++){
          cin >> track[track_i][track_j];
       }
    }
    long long result = gridlandMetro(n, m, k, track);
    cout << result << endl;
    return 0;
}
