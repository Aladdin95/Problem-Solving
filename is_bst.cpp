#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Node {
  int key;
  int left;
  int right;

  Node() : key(0), left(-1), right(-1) {}
  Node(int key_, int left_, int right_) : key(key_), left(left_), right(right_) {}
};

int left_most(int i, const vector<Node>& tree)
{
	int j = i;
	for(j = i; tree[j].left != -1; j = tree[j].left);
	return j;
}

int right_most(int i, const vector<Node>& tree)
{
	int j;
	for(j = i; tree[j].right != -1; j = tree[j].right);
	return j;
}

bool IsBinarySearchTree(const vector<Node>& tree) 
{
	for (int j = 0; j < tree.size(); j++)
	{
		if( (tree[j].left != -1 && tree[j].key <= tree[right_most(tree[j].left, tree)].key )
			|| (tree[j].right != -1 && tree[j].key > tree[left_most(tree[j].right, tree)].key))
			return false;
	}	
	return true;
}

int main() {
  int nodes;
  cin >> nodes;
  vector<Node> tree;
  for (int i = 0; i < nodes; ++i) {
    int key, left, right;
    cin >> key >> left >> right;
    tree.push_back(Node(key, left, right));
  }
  if (nodes == 0 || IsBinarySearchTree(tree)) {
    cout << "CORRECT" << endl;
  } else {
    cout << "INCORRECT" << endl;
  }
  return 0;
}