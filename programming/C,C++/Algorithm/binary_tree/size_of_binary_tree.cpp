/*
size(tree)
1. If tree is empty (root == NULL) then return 0
2. Else
	(a) Get the size of left subtree recursively 
		size(tree->left)
	(b) Get the size of right subtree recursively
		size(tree->right)
	(c) Calculate size of the tree as following:
		tree_size = size(tree->left) + size(tree->right) + 1
	(d) return tree_size
*/


struct node 
{
	int data;
	struct node *left;
	struct node *right;
};

struct node* newNode(int data)
{
	struct node* node = (struct node*)malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return (node);
};

int size(struct node* node)
{
	if (root == NULL)
		return 0;
	int lsize = size(node->left);
	int rsize = size(node->right);

	return lsize + 1 + rsize;
}

nt main() 
{ 
  struct node *root = newNode(1); 
  root->left        = newNode(2); 
  root->right       = newNode(3); 
  root->left->left  = newNode(4); 
  root->left->right = newNode(5);    
  
  printf("Size of the tree is %d", size(root));   
  getchar(); 
  return 0; 
} 
