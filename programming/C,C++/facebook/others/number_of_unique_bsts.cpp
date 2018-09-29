#include <iostream>
#include <vector>

using namespace std;

/*
 * G(n): number of unique bsts using seq 1..n
 * Take element i as root
 * then the elements in the left A[0..(i-1)] will be in left subtree
 * then the elements in the left A[(i+1)..n] will be in right subtree
 * F(i,n): Number of unique bsts with root i using elements from seq 1..n 
 *   num of left subtree of root i * num of right subtree of root i
 * F(i,n) = G(i-1) * G(n-i) 
 *
 * G(n) = F(i,n)            , 1 <= i <= n
 *      = G(i-1) * G(n-i)   , 1 <= i <= n
 *
 * G(0) = 1 // empty tree
 * G(1) = 1 // only root
 *
 *
 * F(n, n) = G(n-1) * G(0)
 * F(n-1, n) = G(n-2) * G(1)
 *     
 */

int number_of_unique_bsts(int n)
{
    int G[n];

    G[0] = 1; // empty tree
    G[1] = 1; // single node as root

    int i, j;
    for(i=2; i<=n; i++)
    {
        for(j=1; j<=i; j++)
        {
            G[i] += G[j-1] * G[i-j];
        }
    }

    return G[n]
}

int main()
{
    int n = 7;
    vector<int> v;
    for(int i=1; i<=n; i++)
        v.push_back(i);

    int r = number_of_unique_bsts(n);
    //vector<int> unique_bsts(v);

    return 0;
}
