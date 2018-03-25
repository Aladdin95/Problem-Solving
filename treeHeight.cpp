#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    int key;
    Node *parent;
    std::vector<Node *> children;

    Node() {
      this->parent = NULL;
    }

    void setParent(Node *theParent) {
      parent = theParent;
      parent->children.push_back(this);
    }
};

int max(int i,int j) {return (i>j)?i:j;}

int treeheight (Node* tree){ 
	if(!tree->children.size()) return 1;
	int height = 0;
	for(int i=0 ; i<tree->children.size() ; ++i){
		height = max( height , treeheight( tree->children[i] ) );
	}
	return height+1;
}

int main() {

  int n,root,j;
  cin >> n;
  vector<Node> tree(n);
  for (int i = 0 ; i<n ; ++i){
	  cin>> j ;
	  tree[i].key=i;
	  if(j==-1)
		  root = i;
	  else
		  tree[i].setParent(&tree[j]);
  }
  cout << treeheight(&tree[root]);
  return 0;
}