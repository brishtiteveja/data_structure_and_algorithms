
int height(struct node* node)
{ 
	if (node == NULL)
		return 0;

	int lheight = height(node->left);
	int rheight = height(node->right);

	return 1 + max(lheight, rheight);
}

int diameter(struct node *tree)
{
	if (tree == NULL)
		return 0;

	int lheight = height(tree->left);
	int rheight = height(tree->right);


	/* It's possible that the diameter is not going through root, rather only contained in a subtree */
	int ldiameter = diameter(tree->left);
	int rdiameter = diameter(tree->right);

	/* 
		max of diameter of left subtree, right subtree, height of left subtree + height of right subtree + 1
	*/
	return max(lheight + rheight + 1, max(ldiameter, rdiameter));
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
  
/* returns maximum of two integers */
int max(int a, int b) 
{ 
  return (a >= b)? a: b; 
}     
  
/* Driver program to test above functions*/
int main() 
{ 
  
  /* Constructed binary tree is  
            1 
          /   \ 
        2      3 
      /  \ 
    4     5 
  */
  struct node *root = newNode(1); 
  root->left        = newNode(2); 
  root->right       = newNode(3); 
  root->left->left  = newNode(4); 
  root->left->right = newNode(5); 
  
  printf("Diameter of the given binary tree is %d\n", diameter(root)); 
  
  getchar(); 
  return 0; 
} 
