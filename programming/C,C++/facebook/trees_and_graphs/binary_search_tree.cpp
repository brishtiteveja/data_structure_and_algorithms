#include <iostream>
#include <stack>

using namespace std;

struct BT{
    int v;
    int visited;
    struct BT* parent;
    struct BT* left;
    struct BT* right;

    bool isBST; // is BST with this node
    int nBst; // number of BSTs under
    int min; // minimum in the left sub tree
    int max; // maximum in the right sub tree

    BT(int x) : v(x), visited(0), left(NULL), right(NULL) {};
};


    /*
     *
     * inorder
     *   if r == null
     *      return 
     *  
     *   if r->left != null
     *      inorder(r->left)
     *
     *   print r
     *
     *   if r->right 
     *      inorder(r->right)
     *
     *          5
     *      6       7
     *    2   3   4 
     *
     *  using iterative
     *
     * stack s                            
     * using dfs we need to keep track whether we have visited the node before 
     *
     * while s not empty                        [5] [6 5] print 2 pop 6 [5] print 6 [3 5] pop 3 [5] print 3 pop 5 [] print 5 push 7  
     *      cur = s.top() 
     *
     *      if cur not visited and cur->left
     *          s.push(cur)        
     *          cur = cur->left           
     *          continue
     *
     *      print cur // left subtree finished
     *      s.pop()
     *                        
     *      if cur not visited and cur->right
     *          s.push(cur)
     *          cur = r->right
     *
     */


void inOrderRecursive(BT* root)
{
    if (root == NULL)
        return;

    if (root->left)
        inOrderRecursive(root->left);

    cout << root->v << " ";

    if (root->right)
        inOrderRecursive(root->right);

    return;
}

void inOrder(BT* root) 
{

    if (root == NULL)
        return;

    BT* cur = root;
    stack<BT*> s;
    s.push(cur);

    while(s.empty() == false) {
        cur = s.top(); 

        if(cur->visited == 0  && cur->left != NULL)
        {
            cur->visited = 1; // Already visited but not all branch explored 
            cur=cur->left;
            s.push(cur);
            //cout << "Left. Pushing " << cur->v << " ." << endl;
            continue;
        }

        cout << cur->v << " ";
        s.pop();

        if(cur->visited <= 1 && cur->right != NULL)
        {
            cur->visited = 2; // Now all branches are completed
            cur=cur->right;
            s.push(cur);
            //cout << "Right. Pushing " << cur->v << " ." << endl;
        }
    }

    return;
}


void preOrderRecursive(BT* root)
{
    if (root == NULL)
        return;

    cout << root->v << " ";

    if (root->left)
        preOrderRecursive(root->left);

    if (root->right)
        preOrderRecursive(root->right);

    return;
}

void preOrder(BT* root) 
{
    if (root == NULL)
        return;

    BT* cur = root;
    stack<BT*> s;
    s.push(cur);

    while(s.empty() == false) {
        cur = s.top(); 

        if (cur->visited == 0)
            cout << cur->v << " ";

        if(cur->visited == 0  && cur->left != NULL)
        {
            cur->visited = 1; // Already visited but not all branch explored 
            cur=cur->left;
            s.push(cur);
            //cout << "Left. Pushing " << cur->v << " ." << endl;
            continue;
        }
        s.pop();

        if(cur->visited <= 1 && cur->right != NULL)
        {
            cur->visited = 2; // Now all branches are completed
            cur=cur->right;
            s.push(cur);
            //cout << "Right. Pushing " << cur->v << " ." << endl;
        }
    }

    return;
}

void postOrderRecursive(BT* root)
{
    if (root == NULL)
        return;


    if (root->left)
        postOrderRecursive(root->left);

    if (root->right)
        postOrderRecursive(root->right);

    cout << root->v << " ";

    return;
}

void postOrder(BT* root) 
{
    if (root == NULL)
        return;

    BT* cur = root;
    stack<BT*> s;
    s.push(cur);

    while(s.empty() == false) {
        cur = s.top(); 


        if(cur->visited == 0  && cur->left != NULL)
        {
            cur->visited = 1; // Already visited but not all branch explored 
            cur=cur->left;
            s.push(cur);
            //cout << "Left. Pushing " << cur->v << " ." << endl;
            continue;
        }


        if(cur->visited <= 1 && cur->right != NULL)
        {
            cur=cur->right;
            s.push(cur);
            continue;
            //cout << "Right. Pushing " << cur->v << " ." << endl;
        }

        cout << cur->v << " ";
        cur->visited = 2; 
        s.pop();

    }

    return;
}


BT* createTree()
{
    BT* tree = new BT(25);

    tree->left = new BT(18);
    tree->left->left = new BT(19);
    tree->left->left->right = new BT(15);

    tree->left->right = new BT(20); 
    tree->left->right->left = new BT(18); 
    tree->left->right->right = new BT(25); 

    tree->right = new BT(50);
    tree->right->left = new BT(35);
    tree->right->right = new BT(60);
    

    tree->right->left->left = new BT(20);
    tree->right->left->right = new BT(40);
    tree->right->left->left->right = new BT(25);

    tree->right->right = new BT(60);
    tree->right->right->left = new BT(55);
    tree->right->right->right = new BT(70);

    return tree;
}


int main()
{
    BT* tree = createTree();
    cout << "In Order Recursive" << endl;
    inOrderRecursive(tree);
    cout << endl;
    cout << endl;

    cout << "In Order Iterative" << endl;
    inOrder(tree);
    cout << endl;
    cout << endl;

    tree = createTree();

    cout << "Pre Order Recursive" << endl;
    preOrderRecursive(tree);
    cout << endl;
    cout << endl;

    cout << "Pre Order Iterative" << endl;
    preOrder(tree);
    cout << endl;
    cout << endl;

    tree = createTree();
    cout << "Post Order Recursive" << endl;
    postOrderRecursive(tree);
    cout << endl;
    cout << endl;

    cout << "Post Order Iterative" << endl;
    postOrder(tree);
    cout << endl;
    cout << endl;

    return 0;
}
