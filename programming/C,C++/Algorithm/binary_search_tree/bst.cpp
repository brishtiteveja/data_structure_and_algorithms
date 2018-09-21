#include <iostream>
#include <cstdio>

using namespace std;

typedef struct node {
    int x;
} Node;

typedef struct btree {
    Node root;
    struct btree* left;
    struct btree* right;
} Btree;

// insertion
Btree* insert(Btree* tree, Node n) {
    if (tree == NULL) {
        tree = new Btree();
        tree->root = n;
        tree->left = NULL;
        tree->right = NULL;
        return tree;
    }

    Node root = tree->root;
    if (n.x <= root.x) {
        tree->left = insert(tree->left, n);
    } else {
        tree->right = insert(tree->right, n);
    }

    return tree;
}

// left, root, right
void print_inorder(Btree* tree) {
    if (tree == NULL) {
        return;
    }

    print_inorder(tree->left);
    Node root = tree->root;
    cout << root.x << " "; 
    print_inorder(tree->right);

    return;
}

// root, left, right
void print_preorder(Btree* tree) {
    if (tree == NULL) {
        return;
    }

    Node root = tree->root;
    cout << root.x << " "; 
    print_preorder(tree->left);
    print_preorder(tree->right);

    return;
}

// left, right, root
void print_postorder(Btree* tree) {
    if (tree == NULL) {
        return;
    }

    print_postorder(tree->left);
    print_postorder(tree->right);
    Node root = tree->root;
    cout << root.x << " "; 

    return;
}

void search(Btree* tree, int x) {
    if (tree == NULL) {
        return;
    }
    Node root = tree->root;
    if (root.x == x) {
        cout << x << " was found";
    } else if (x <= root.x) {
        cout << root.x << " ";
        search(tree->left, x);
    } else {
        cout << root.x << " ";
        search(tree->right, x);
    }

    return;
}

int main() {
//                            10
//                          /    \
//                         5     18
//                       /   \
//                      2     6
//                       \
//                        4
    Btree* tree = NULL;
    Node n;
    n.x=10;
    tree = insert(tree, n);
    n.x=5;
    insert(tree, n);
    n.x=18;
    insert(tree, n);
    n.x=2;
    insert(tree, n);
    n.x=6;
    insert(tree, n);
    n.x=4;
    insert(tree, n);

    print_inorder(tree);
    cout << endl;

    print_preorder(tree);
    cout << endl;

    print_postorder(tree);
    cout << endl;

    search(tree, 4);
    cout << endl;
 
    return 0;
}
