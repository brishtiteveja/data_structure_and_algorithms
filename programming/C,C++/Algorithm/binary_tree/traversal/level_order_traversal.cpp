#include <iostream>
#include <cstdio>
#include <stack>
#include <queue>


using namespace std;

struct Node 
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* newNode(int data) 
{
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

void dfs(struct Node* root) {
    // BFS
    stack<struct Node*> s;

    s.push(root);

    while(s.empty() == false) 
    {
        struct Node* node = s.top();
        s.pop();

        cout << node->data << " ";

        struct Node* right = node->right;
        if (right != NULL)
            s.push(right);
        struct Node* left = node->left;
        if (left != NULL)
            s.push(left);
    }

    return;
}

void levelorder(struct Node* root) {
    // BFS
    queue<struct Node*> q;

    q.push(root);

    while(q.empty() == false) 
    {
        struct Node* node = q.front();
        q.pop();

        cout << node->data << " ";

        struct Node* left = node->left;
        if (left != NULL)
            q.push(left);
        struct Node* right = node->right;
        if (right != NULL)
            q.push(right);
    }
}

void inorder(struct Node* root) 
{
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);

    return;
}

void preorder(struct Node* root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);

    return;
}

void postorder(struct Node* root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";

    return;
}


int main() 
{
    struct Node* tree = newNode(1);
    tree->left = newNode(2);
    tree->right = newNode(5);
    tree->left->left = newNode(3);
    tree->left->right = newNode(4);

    inorder(tree);
    cout << endl;
    preorder(tree);
    cout << endl;
    postorder(tree);
    cout << endl;
    levelorder(tree);
    cout << endl;
    dfs(tree);
    cout << endl;

    return 0;
}
