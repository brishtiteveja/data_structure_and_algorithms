#include <cstdio>
#include <cstdlib>

/* A binary tree node has data, pointer to left child and a pointer to right child */

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

/* function to create a new node of tree and returns pointer */
struct Node* newNode(int data) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;

    return(node);
}

/* function to convert a tree to double tree */
void doubleTree(struct Node* node)
{
    struct Node* oldLeft;

    if(node == NULL)
        return;

    /* do the subtrees */
    doubleTree(node->left);
    doubleTree(node->right);

    /* duplicate this node to its left */
    oldLeft = node->left;
    node->left = newNode(node->data);
    node->left->left = oldLeft;
}

/* Given a binary tree, print its nodes in inorder*/
void printInorder(struct node* node) 
{ 
  if (node == NULL) 
    return; 
  printInorder(node->left);  
  printf("%d ", node->data); 
  printInorder(node->right); 
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
   
  printf("Inorder traversal of the original tree is \n"); 
  printInorder(root); 
  
  doubleTree(root); 
    
  printf("\n Inorder traversal of the double tree is \n");   
  printInorder(root); 
     
  getchar(); 
  return 0; 
} 
