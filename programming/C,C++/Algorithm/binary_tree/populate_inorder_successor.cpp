#include <cstdio>
#include <cstdlib>

struct node
{
	int data;
	struct node *left;
	struct node *right;
	struct node *next;
};

/* Set next of p and all descendents of p by traversing them in reverse Inorder  */


/* UTILITY FUNCTIONS */
/* Helper function that allocates a new node with the 
   given data and NULL left and right pointers. */
struct node* newnode(int data) 
{ 
    struct node* node = (struct node*) 
                        malloc(sizeof(struct node)); 
    node->data = data; 
    node->left = NULL; 
    node->right = NULL; 
    node->next = NULL; 
  
    return(node); 
} 
  
/* Driver program to test above functions*/
int main() 
{ 
  
    /* Constructed binary tree is 
              10 
            /   \ 
          8      12 
        / 
      3 
    */
    struct node *root = newnode(10); 
    root->left        = newnode(8); 
    root->right       = newnode(12); 
    root->left->left  = newnode(3); 
  
    // Populates nextRight pointer in all nodes 
    populateNext(root); 
  
    // Let us see the populated values 
    struct node *ptr = root->left->left; 
    while(ptr) 
    { 
        // -1 is printed if there is no successor 
        printf("Next of %d is %d \n", ptr->data, ptr->next? ptr->next->data: -1); 
        ptr = ptr->next; 
    } 
  
    return 0; 
} 
