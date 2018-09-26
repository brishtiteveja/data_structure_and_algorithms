#include <iostream>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL){};
};

class Solution 
{
    public:
        void flatten(TreeNode *root)
        {
            // empty tree or leaf node
            if (root == NULL || (root->left == NULL && root->right == NULL)) 
            {
                   return;
            }

            // if root->left exists then we have to make it root->right
            if (root->left != NULL)
            {
                // move left recursively
                flatten(root->left);

                // store the node root->right
                TreeNode *tmpRight = root->right;
                root->right = root->left;
                root->left = NULL;

                // find the position to insert the stored root->right
                TreeNode *t = root->right;
                while(t->right != NULL)
                {
                    t = t->right;
                }
                
                //insert
                t->right = tmpRight;
            }

            // now flatten root->right
            flatten(root->right);

            return;
        }
};

void inorder(TreeNode *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

void preorder(TreeNode *root)
{
    if (root == NULL)
        return;

    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    TreeNode *tree; 
    tree = new TreeNode(1);
    tree->left = new TreeNode(2);
    tree->right = new TreeNode(5);
    tree->left->left = new TreeNode(3);
    tree->left->right = new TreeNode(4);
    tree->right->left = NULL;
    tree->right->right = new TreeNode(6);

    inorder(tree);
    cout << endl;

    Solution sol;
    sol.flatten(tree);

    inorder(tree);
    cout << endl;
}
