// C++ program to find height of tree
#include <bits/stdc++.h>
using namespace std;
class node
{
    public:
    int data;
    node* left;
    node* right;
};
int maxDepth(node* node)
/* Pass the node below which height needs to be calculated, if node= ROOT, then total height is given */
{
	if (node == NULL)
		return -1;
	else
	{
		/* compute the depth of each subtree (left and right) */
		int lDepth = maxDepth(node->left);
		int rDepth = maxDepth(node->right);
	
		/* use the larger one */
		if (lDepth > rDepth)
			return(lDepth + 1);
		else return(rDepth + 1);
	}
}
node* newnode(int data) // object in a class
{
  node* Node=  new node();
  Node->data=data;
  Node->left=NULL;
  Node->right=NULL;
  return Node;
}
int main()
{
	/* Initialising a tree */
    node* root=newnode(1);
    root->left=newnode(2);
    root->right = newnode(3);
	root->left->left = newnode(3);
	root->left->right = newnode(3);
	cout << "Height of tree is " << maxDepth(root);
	return 0;
}