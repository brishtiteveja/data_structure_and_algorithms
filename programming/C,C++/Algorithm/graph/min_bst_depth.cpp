#include<bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    struct Node *left, *right;
};

struct qItem {
    Node *node;
    int depth;
};

int minDepth(Node *root) {
    // Corner case
    if (root == NULL)
        return 0;

    queue<qItem> q;

    qItem qi = {root, 1};
    q.push(qi);

    while(q.empty() == false) {
        qi = q.front();
        q.pop();

        Node *node = qi.node;
        int depth = qi.depth;

        if (node->left == NULL && node->right == NULL)
            return depth;
        if (node->left != NULL) {
            qi = node->left;
            qi.depth = depth + 1;
            q.push(qi);
        }

        if (node->right != NULL) {
            qi = node->right;
            qi.depth = depth + 1;
            q.push(qi);
        }
        
    }

}
