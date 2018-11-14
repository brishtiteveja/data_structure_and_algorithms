#include<iostream>

using namespace std;

#define CHAR_TO_INDEX(c) ((int)c - (int)'a')

/*
 * Trie is an efficient information retrieval data structure. Using Trie, search complexities can be brought down to optimal limit(key length). If we store keys in binary search tree, a well balanced BST will need time proportional to M*log N, where M is maximm string length and N is the number of keys in tree. Using Trie, we can search the key in O(M) time. However, the penalty is on Trie storage requirements.
 *
 */

const int ALPHABET_SIZE = 26;

// trie node
struct TrieNode
{
    struct TrieNode *children[ALPHABET_SIZE];

    // isEndOfWord is true if the node represents end of a word
    bool isEndOfWord;
};


// Returns new trie node (initialized to NULLs)
struct TrieNode *getNode(void)
{
    struct TrieNode *pNode = new TrieNode;

    pNode->isEndOfWord = false;
    
    for(int i=0; i<ALPHABET_SIZE; i++)
        pNode->children[i] = NULL;

    return pNode;
}

/*
 * Inserting a key into Trie is simple approach. Every character of input key is inserted as an individual Trie node. Note that the children is an array of pointers (or references) to next level trie nodes. The key character acts as an index into the array children. If the input key is new or an extension of existing key, we need to construct non-existing nodes of the key, and mark end of word for last node. If the input key is prefix of existing key in Trie, we simply mark the last node of key as end of word. The key leangth determines Trie depth.
 *
 *                   root
 *                 /   |   \
 *                t    a(E) b
 *                |    |    |
 *                h    n    y
 *                |    | \  |
 *                e(E) s  y e(E)
 *            /   |    |    
 *          i     r    w   
 *          |     |    |
 *         r(E)   e(E) e 
 *                     |
 *                     r(E)
 */

// If not present, inserts key into trie
// If the key is prefix of trie node, just marks leaf node
void insert(struct TrieNode *root, string key)
{
    struct TrieNode *pCrawl = root;

    for(int i=0; i<key.length(); i++) {
        int index = key[i]i - 'a'; // index for the current character 
        if(pCrawl->children[index] != NULL) 
        {
            pCrawl->children[index] = getNode();
        }

        // go to the children
        pCrawl = pCrawl->children[index];
    }

    pCrawl->isEndofWord = true;

    return;
}

/*
 * Searching for a key is similar to insert operation, however we only compare the characters and move down. The search can terminate due to end of string or lack of key in trie. In the former case, if the isEndofWord field of last node is true, then the key exists in trie. In the second case, the search terminates without examining all the characers of key, since the key is not present in trie.
 *
 */
// Returnds true if key presents in trie, else false
bool search(struct TrieNode *root, string key)
{
    struct TrieNode *pCrawl = root; 

    for (int i=0; i<key.length(); i++)
    {
        int index = key[i] - 'a';
        if (pCrawl->children[index] == NULL)
            return false;

        pCrawl = pCrawl->children[index];
    }

    return (pCrawl != NULL && pCrawl->isEndOfWord);
}

// Auto completion feature using trie
// 
// Returns 0 if current node has a child
// If all children are NULL, return 1
bool isLastNode(struct TrieNode *root)
{
    for (int i=0; i<ALPHABET_SIZE; i++)
    {
        // If there exists a single children, it's not a last node
        if (root->children[i])
            return 0;
    }

    return 1;
}

// Recursive function to print auto-suggestions for given node
void suggestionsRec(struct TrieNode *root, string currPrefix)
{
    // found a string in Trie with the given prefix
    if (root->isWordEnd)
    {
        cout << currPrefix;
        cout << endl;
    }

    // All children struct node pointers are NULL
    if (isLastNode(root))
        return;

    for(int i=0; i<ALPHABET_SIZE; i++)
    {
        // For all existing children recur
        if(root->children[i])
        {
            // append current character to currPrefix string
            currPrefix.push_back(97 + i);

            // recur over the rest
            suggestionsRec(root->children[i], currPrefix);
        }
    }
}

// print suggestions for given query prefix
int printAutoSuggestions(TrieNode* root, const string query)
{
    struct TrieNode *pCrawl = root;

    // Check if prefix is present and find the node (of last level) with last character of given string
    int level;
    int n = query.length();
    for(level=0; level<n; level++)
    {
        int index = CHAR_TO_INDEX(query[level]);

        if (!pCrawl->children[index])
            return 0;

        pCrawl = pCrawl->children[index];
    }

    // If prefix is present as a word
    bool isWord = (pCrawl->isWordEnd == true);

    // If prefix is last node of tree (has no children)
    bool isLast = isLastNode(pCrawl);

    // If prefix is present as a word, but there is no subtree below the last matching node
    if (isWord && isLast)
    {
        cout << query << endl;
    }
    
    // If there are nodes below last matching character
    if (!isLast)
    {
        string prefix = query;
        suggestionsRec(pCrawl, prefix);

        return 1;
    }
}

// Driver
int main()
{
    // Input keys (use only 'a' through 'z'
    // and lower case)
    string keys[] = {"the", "a", "there",
                     "answer", "any", "by",
                     "bye", "their" };

    int n = sizeof(keys)/sizeof(keys[0]);

    struct TrieNode *root = getNode();

    // Construct trie
    for (int i=0; i<n; i++)
    {
        insert(root, keys[i]);
    }

    // Search for different keys
    search(root, "the") ? cout << "Yes\n" : cout << "No\n" << endl;
}
    search(root, "these") ? cout << "Yes\n" : cout << "No\n" << endl;

    return 0;
