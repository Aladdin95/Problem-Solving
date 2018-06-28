#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cin;
using std::cout;
using std::swap;
using std::pair;
using std::make_pair;

class HeapBuilder {
 private:
  vector<int> data_;
  vector< pair<int, int> > swaps_;

  void WriteResponse() const {
    cout << swaps_.size() << "\n";
    for (int i = 0; i < swaps_.size(); ++i) {
      cout << swaps_[i].first << " " << swaps_[i].second << "\n";
    }
  }

  void ReadData() {
    int n;
    cin >> n;
    data_.resize(n);
    for(int i = 0; i < n; ++i)
      cin >> data_[i];
  }

  void sift_down(int i)
  {
	  int L = 2*i+1;
	  int R = L+1;
	  int n = data_.size();
	  int min = i;
	  if(L < n && data_[min] > data_[L])
		  min = L;
	  if(R < n && data_[min] > data_[R])
		  min = R;
	  if(min != i){
		  swap(data_[i],data_[min]);
		  swaps_.push_back(make_pair(i, min));
		  sift_down(min);
	  }
  }
  void GenerateSwaps() {
    swaps_.clear();
	for (int i = data_.size()/2; i >= 0 ; i--)
	{
		sift_down(i);
	}
  }

 public:
  void Solve() {
    ReadData();
    GenerateSwaps();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  HeapBuilder heap_builder;
  heap_builder.Solve();
  return 0;
}
