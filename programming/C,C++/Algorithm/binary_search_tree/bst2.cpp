#include <iostream>


using namespace std;

struct BTreeNode {
    int x;
    struct BTreeNode* left;
    struct BTreeNode* right;
};

void insert(BTreeNode** root, int x) {
    BTreeNode* p = *root;
    if (p == NULL) {
        p = new BTreeNode();
        p->x = x;
        p->left = NULL;
        p->right = NULL;
        *root = p;
    } else if (x < p->x) {
        insert(&p->left, x);
    } else {
        insert(&p->right, x);
    }

    return;
}

void print(BTreeNode* root) {
    if (root == NULL)
        return;
    print(root->left);
    cout << root->x << " "; 
    print(root->right);

    return;
}

int main() {
    BTreeNode** root;
    *root = NULL;

    insert(root, 10);
    insert(root, 11);
    insert(root, 5);
    insert(root, 18);

    print(*root);

    return 0;
};
