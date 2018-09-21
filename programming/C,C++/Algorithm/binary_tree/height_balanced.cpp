/*
	A tree where no leaf is much farther away from the root than any other leaf. DIfferent balancing schemes allow different definitions of "much farther" and different amounts of work to keep them balanced.
	An empty tree is height-balanced. A non-empty binary tree T is balanced if:
	1) Left subtree of T is balanced
	2) Right subtree of T is balanced
	3) The difference between heights of left subtree and right subtree is nor more than 1
*/


/* C program to check if a tree is height-balanced or not */
#include<stdio.h> 
#include<stdlib.h> 
#define bool int 
  
/* A binary tree node has data, pointer to left child 
   and a pointer to right child */
struct node 
{ 
    int data; 
    struct node* left; 
    struct node* right; 
}; 

/*
	The function Compute the "height" of a tree. Height is the number of nodes along the longest path from the root node down to the farthest leaf node 
*/
int height(struct node* node)
{
	/* base case tree is empty */
	if(node == NULL)
		return 0;
	/* If tree is not empty then height = 1 + max of left height and right heights */
	return 1 + max(height(node->left), height(node->right));
}

/* Returns true if binary tree with root as root is height-balanced */
bool isBalanced(struct node *root)
{
	/* If tree is empty then return true */
	if (root == NULL)
		return 1;

	int lh; /* for height of left subtree */
	int rh; /* for height of right subtree */

	/* Get the height of left and right sub trees */
	lh = height(root->left);
	rh = height(root->right);

	if (abs(lh-rh) <= 1 && 
		isBalanced(root->left) &&
		isBalanced(root->right))
	{
		return 1;
	}

	/* If we reach here then tree is not height-balanced */
	return 0;
}

int max(int a, int b)
{
	return (a>=b)? a : b;
}
/* Helper function that allocates a new node with the 
   given data and NULL left and right pointers. */
struct node* newNode(int data) 
{ 
    struct node* node = (struct node*) 
                                malloc(sizeof(struct node)); 
    node->data = data; 
    node->left = NULL; 
    node->right = NULL; 
  
    return(node); 
} 
  
int main() 
{ 
    struct node *root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->left->left->left = newNode(8); 
  
    if(isBalanced(root)) 
      printf("Tree is balanced"); 
    else
      printf("Tree is not balanced");     
  
    getchar(); 
    return 0; 
} 
