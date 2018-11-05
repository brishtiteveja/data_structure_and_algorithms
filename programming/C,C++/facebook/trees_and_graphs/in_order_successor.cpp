#include <iostream>

using namespace std;

struct TreeNode
{
    int val;
    Node *left;
    Node *right;

    TreeNode(int x) : val(x), left = NULL, right = NULL {};
};

// Helper function that allocates a new Node
TreeNode* newNode(int val)
{
    TreeNode* n = new TreeNode;
    n->key = key;
    n->left = nullptr;
    n->right = nullptr;

    return n;
}

    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (p->right != NULL)
            return findSmallestLeafNode(p->right);
        else {   
            TreeNode* parent = searchParentNode(root, p);
            if (parent == NULL) {
                return NULL;
            }
            else if (p == parent->left) {
                return parent;   
            }
            else {
                while (p == parent->right) {
                    parent = searchParentNode(root, parent);     
                    if (parent == NULL)
                        return NULL;
                }
                    
                return parent;
            }
        }
    }
