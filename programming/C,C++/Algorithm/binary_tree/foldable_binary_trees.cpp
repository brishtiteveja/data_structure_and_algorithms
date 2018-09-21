// A tree can be folded if left and right subtrees of the tree are structure wise mirror image of each other. An empty tree is considered as foldable

/*
Consider the below trees:
(a) and (b) can be folded.
(c) and (d) cannot be folded.

(a)
       10
     /    \
    7      15
     \    /
      9  11

(b)
        10
       /  \
      7    15
     /      \
    9       11

(c)
        10
       /  \
      7   15
     /    /
    5   11

(d)

         10
       /   \
      7     15
    /  \    /
   9   10  12


*/


#include<stdio.h> 
#include<stdlib.h> 
  
/* You would want to remove below 3 lines if your compiler 
   supports bool, true and false */
#define bool int 
#define true 1 
#define false 0 
  
/* A binary tree node has data, pointer to left child 
   and a pointer to right child */
struct node 
{ 
  int data; 
  struct node* left; 
  struct node* right; 
}; 
  
bool isStructSame(struct node *a, struct node *b)
{
	if (a == NULL && b == NULL)
	{
		return true;
	}

	if (a != NULL && b != NULL
		&& isStructSame(a->left, b->left) 
		&& isStructSame(a->right, b->right)) 
	{
		return true;
	}

	return false;
}

void mirror(struct node *node)
{
	if (node == NULL)
		return;
	else
	{
		struct node *temp;

		mirror(node->left);
		mirror(node->right);

		/* swap the pointers in this node */
		temp = node->left;
		node->left = node->right;
		node->right = temp;
	}
}

/* Returns true if the given tree is foldable */
bool isFoldable(struct node *root)
{
	bool res;

	/* base case */
	if (root == NULL)
		return true;

	/* convert left subtree to its mirror */
	mirror(root->left);

	/* Compare the structures of the right subtree and mirrored left subtree */
	res = isStructSame(root->left, root->right);

	/* Get the original tree back */
	mirror(root->left);

	return res;
}
