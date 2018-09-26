#include <iostream>

using namespace std;

struct Node
{
    int key;
    Node *left;
    Node *right;
    Node *parent;
};

// Helper function that allocates a new Node
Node* newNode(int key)
{
    Node* n = new Node;
    n->key = key;
    n->left = nullptr;
    n->right = nullptr;
    n->parent = nullptr;

    return n;
}



// Given a binary search tree and a number, inserts a new Node with the given number in the correct place in the tree. Returns the root pointer which the caller should then use
Node *insert(Node *root, int key)
{
    if (root == nullptr)
        return newNode(key);

    Node *temp;
    if (key < root->key)
    {
       temp = insert(root->left, key); 
       root->left = temp;
       temp->parent = root;
    } else 
    {
        temp = insert(root->right, key);
        root->right = temp;
        temp->parent = root;
    }

    return root;
}

// inorder traversal
void inorder(Node* root)
{
    if (root == nullptr)
        return;
    
    inorder(root->left);
    cout << root->key << " ";
    inorder(root->right);

    return;
}


Node *getNodeByKey(Node *root, int key)
{
    Node *currentNode = root;

    while(currentNode) 
    {
        if (key == currentNode->key)
        {
            return currentNode;
        }

        if (key < currentNode->key)
        {
            currentNode = currentNode->left;
        } else
        {
            currentNode = currentNode->right;
        }
    }

    return nullptr;
}

/*
 * Node* findSmallest(root)
 *   a) if root->left == null && root->right == null
 *          return root
 *   b) else
 *          return findSmallest(root->left)
 *           
 *
 * 
 * Node* delete(root, key):
 *   a) empty tree
 *      if root == null
 *         return null
 *   b) key is a leaf node
 *      if root->key == key && root->left == null && root->right == null
 *        if (root->parent->left == root)
 *          root->parent->left = null
 *        else 
 *          root->parent->right = null
 *        free(root)
 *        return root
 *   c) 
 *     find the node with the smallest key in the right subtree
 *     Node* snode = findSmallest(root->right);
 *     snode->parent->left = null;
 *     if root->parent->left == root
 *        root->parent->left = snode
 *     else
 *        root->parent->right = snode
 *     snode->left = root->left
 *     snode->right = root->right
 *     free(root)
 *     
 *     root = snode
 *
 *  return root
 */

Node* findSmallestLeafNode(Node* root) 
{
    if (root == nullptr) {
        return nullptr;
    }
    else if (root->left == nullptr && root->right == nullptr) {
        return root;
    } else {
        if (root->left != nullptr)
            return findSmallestLeafNode(root->left);
        else
            return findSmallestLeafNode(root->right);
    }
}

/*
 *  Still problem with root deletion, multiple neighbor deletion
 *
 *
 */

Node* deleteNode(Node* root, int key) 
{
    if (root == nullptr)
        return nullptr;
    if (root->key == key)
    {
        // leaf node
        if (root->left == nullptr && root->right == nullptr)
        {
            if (root->parent->left == root)
                root->parent->left = nullptr;
            else 
                root->parent->right = nullptr;
            free(root);
        } else 
        {
            if(root->right == nullptr)
            {
                if (root->parent != nullptr)
                {
                    if (root->parent->left == root) {
                        root->parent->left = root->left;
                    } else
                    {
                        root->parent->right = root->left; 
                    }
                    free(root);
                }
                else
                {
                    root = root->left;
                    Node *temp = root;
                    free(temp);
                }
            }

            Node *sn = findSmallestLeafNode(root->right);

            // change the smallest node's parent's left child to null
            // if parent is the super root
            if (sn->parent != nullptr)
            {
                // set the parent's left/right to null
                if (sn->parent->left == sn)
                {
                    sn->parent->left = nullptr;
                } else
                {
                    sn->parent->right = nullptr;
                }
            }

            // point the parent of root to left or right
            if (root->parent != nullptr)
            {
                if(root->parent->left == root)
                    root->parent->left = sn;
                else
                    root->parent->right = sn;
            }

            sn->left = root->left;
            sn->right = root->right;
            free(root);
        
            root = sn;
        }
    } else if (key < root->key)
    {
        deleteNode(root->left, key);
    } else 
    {
        deleteNode(root->right, key);
    }

    return root;
}


Node* findInOrderSuccessor(Node *inputNode)
{
   return nullptr; 
}

Node* createTree(Node* t)
{
    t = insert(t, 20);
    t = insert(t, 9);
    t = insert(t, 25);
    t = insert(t, 5);
    t = insert(t, 12);
    t = insert(t, 11);
    t = insert(t, 14);

    return t;
}

Node* freeTree(Node* t)
{
    if (t == nullptr)
        return nullptr;
    else
    {
        freeTree(t->left);
        freeTree(t->right);
        
        free(t);

        return nullptr;
    }
}

int main()
{
    Node* t = nullptr;
    t = createTree(t);

    inorder(t);
    cout << endl;

    cout << "Deleted Node 12" << endl;
    deleteNode(t, 12);

    inorder(t);
    cout << endl;

    t = freeTree(t);
    t = createTree(t);

    //deleteNode(t, 12);
    cout << "Deleted Node 9" << endl;
    deleteNode(t, 9);

    inorder(t);
    cout << endl;

    t = freeTree(t);
    t = createTree(t);

    //deleteNode(t, 12);
    cout << "Deleted Node 25" << endl;
    deleteNode(t, 25);

    inorder(t);
    cout << endl;

    t = freeTree(t);
    t = createTree(t);

    //deleteNode(t, 20);
    cout << "Deleted Node 11" << endl;
    deleteNode(t, 11);
    cout << "Deleted Node 9" << endl;
    deleteNode(t, 9);


    inorder(t);
    cout << endl;

    t = freeTree(t);
    t = createTree(t);

    //deleteNode(t, 20);
    cout << "Deleted Node 20" << endl;
    deleteNode(t, 20);


    inorder(t);
    cout << endl;
    return 0;
}
