#include <cstdio>
#include <cstdlib>

// A binary tree node
struct Node 
{
	int data;
	struct Node *left, *right;
};

// A utility function to create a new binary tree node
struct Node *newNode(int item)
{
	struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
	temp->data = item;
	temp->left = temp->right = NULL;
	return temp;
};

// Recursive function to check if two Nodes are siblings
int isSibling(struct Node *root, struct Node *a, struct Node *b)
{
	if (root == NULL) {
		return 0;
	}

	return ((root->left == a && root->right == b) ||
			(root->left == b && root->left  == a) ||
			isSibling(root->left, a, b) || 
			isSibling(root->right, a, b));
}

// Recursive function to find level of Node 'ptr' in a binary tree
int level(struct Node *root, struct Node *ptr, int lev)
{
	if(root == NULL)
		return 0;
	if(root == ptr)
		return lev;

	int l = level(root->left, ptr, lev + 1);

	if (l != 0)
		return l;

	return level(root->right, ptr, lev + 1);
}

/*
      	1 			lev = 0
	/   	\
   2     	 3      lev = 1 
 /   \     /    
3     4   6         lev = 2 

*/

// Returns 1 if a and b are cousins, otherwise 0
int isCousin(struct Node *root, struct Node *a, struct Node *b) 
{
	if ( (level(root, a, 1) == level(root, b, 1) && 
		!isSibling(root, a, b)) )
		return 1;
	else
		return 0;
}

// Driver Program to test above functions
int main ()
{
	struct Node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->left->right = newNode(8);

	struct Node *Node1, *Node2;
	Node1 = root->left->left;
	Node2 = root->right->right;

	isCousing(root, Node1, Node2) ? cout << "Yes" << endl : cout << "No" << endl;

	return 0;
}
