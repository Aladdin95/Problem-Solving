#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using std::vector;
using std::cin;
using std::cout;
using std::swap;
using std::pair;
using std::make_pair;

class JobQueue {
 private:
  int num_workers_;
  vector<int> jobs_;

  vector<int> assigned_workers_;
  vector<long long> start_times_;
  vector<pair<int,long long>> heap;

  void WriteResponse() const {
    for (int i = 0; i < jobs_.size(); ++i) {
      cout << assigned_workers_[i] << " " << start_times_[i] << "\n";
    }
  }

  void ReadData() {
    int m;
    cin >> num_workers_ >> m;
    jobs_.resize(m);
    for(int i = 0; i < m; ++i)
      cin >> jobs_[i];
  }

  void sift_down(int i)
  {
	  int L = 2*i+1;
	  int R = L+1;
	  int n = heap.size();
	  int min = i;
	  if(L < n && heap[min].second > heap[L].second)
		  min = L;
	  else if(L < n && heap[min].second == heap[L].second && heap[min].first > heap[L].first)
		  min = L;
	  if(R < n && heap[min].second > heap[R].second)
		  min = R;
	  else if(R < n && heap[min].second == heap[R].second && heap[min].first > heap[R].first)
		  min = R;
	  if(min != i){
		  swap(heap[i],heap[min]);
		  //swaps_.push_back(make_pair(i, min));
		  sift_down(min);
	  }
  }

  void sift_up(int i)
  {
	  int P = (i-1)/2;
	  if(P >= 0 && heap[i].second < heap[P].second){
		  swap(heap[i],heap[P]);
		  sift_up(P);
	  }
	  else if(P >= 0 && heap[i].second == heap[P].second && heap[i].first < heap[P].first){
		  swap(heap[i],heap[P]);
		  sift_up(P);
	  }
  }

  void AssignJobs() {
    assigned_workers_.resize(jobs_.size());
    start_times_.resize(jobs_.size());
	
	int i;
	for (i = 0 ; i < num_workers_ && i < jobs_.size() ; i++)
	{
		assigned_workers_[i] = i;
		start_times_[i] = 0;
		heap.push_back(make_pair(i,jobs_[i]));
		sift_up(heap.size()-1);
	}

	for (; i < jobs_.size(); i++)
	{
		assigned_workers_[i] = heap[0].first;
		start_times_[i] = heap[0].second;
		heap[0].second += jobs_[i];
		sift_down(0);
	}
  }

 public:
  void Solve() {
    ReadData();
    AssignJobs();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  JobQueue job_queue;
  job_queue.Solve();
  return 0;
}
