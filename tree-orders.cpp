#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class TreeOrders {
  int n;
  vector <int> key;
  vector <int> left;
  vector <int> right;

public:
  void read() {
    cin >> n;
    key.resize(n);
    left.resize(n);
    right.resize(n);
    for (int i = 0; i < n; i++) {
      cin >> key[i] >> left[i] >> right[i];
    }
  }

  void in_order(int i, vector<int> &v){
	  if(left[i]!=-1)
		in_order(left[i],v);
	  v.push_back(key[i]);
	  if(right[i]!=-1)
		in_order(right[i],v);
  }
  void pre_order(int i, vector<int> &v){
	  v.push_back(key[i]);
	  if(left[i]!=-1)
		pre_order(left[i],v);
	  if(right[i]!=-1)
		pre_order(right[i],v);
  }
  void post_order(int i, vector<int> &v){
	  if(left[i]!=-1)
		post_order(left[i],v);
	  if(right[i]!=-1)
		post_order(right[i],v);
	  v.push_back(key[i]);
  }
  vector <int> in_order() {
    vector<int> result;
	result.reserve(key.size());
	in_order(0,result);
    return result;
  }

  vector <int> pre_order() {
    vector<int> result;    
	result.reserve(key.size());
	pre_order(0,result);
	return result;
  }

  vector <int> post_order() {
    vector<int> result;
	result.reserve(key.size());
	post_order(0,result);
    return result;
  }
};

void print(vector <int> a) {
  for (size_t i = 0; i < a.size(); i++) {
    if (i > 0) {
      cout << ' ';
    }
    cout << a[i];
  }
  cout << '\n';
}

int main (int argc, char **argv)
{
  TreeOrders t;
  t.read();
  print(t.in_order());
  print(t.pre_order());
  print(t.post_order());
  return 0;
}

