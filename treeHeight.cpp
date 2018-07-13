#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    int key;                        //value of the node
    Node *parent;                   //pointer to its parent
    std::vector<Node *> children;   //vector of pointers of its children

    Node() {                        //empty constructor
      this->parent = NULL;
    }

    void setParent(Node *theParent) {          //set the parent of this node
      parent = theParent;
      parent->children.push_back(this);        //dont forget to add this node to the children of the parent
    }
};

int max(int i,int j) {return (i>j)?i:j;}

int treeheight (Node* tree){                     //take a pointer to the root
	if(!tree->children.size()) return 1;         //stopping condition of recursion when the node has no children
	int height = 0;
	for(int i=0 ; i < tree->children.size() ; ++i){
		height = max( height , treeheight( tree->children[i] ) ); //call the same function to all the branches of children and return the max branch height 
	}
	return height+1;
}

int main() {

  int n,root,j;
  cin >> n;
  vector<Node> tree(n);
  for (int i = 0 ; i<n ; ++i){
	  cin>> j ;
	  tree[i].key=i;             //key = the index of the input
	  if(j==-1)
		  root = i;
	  else
		  tree[i].setParent(&tree[j]);
  }
  cout << treeheight(&tree[root]);
  return 0;
}