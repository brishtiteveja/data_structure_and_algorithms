#include <iostream>
#include <vector>

using namespace std;

#define FOR(i, n) for(int i=0; i<n; i++)

/*
 * Naive solution
 *
 while there's untried configuration
    generate next configuration

    if there's edge connection between two consecutive vertices in the configuration and all vertices exist in the path exactly once
        print the configuration
        break

 */

/*
 * In brute force, you generate all the possible combinations you can and then you check if any of them is the answer you want
 * In backtracking, in each step you check whether this step satisfies all the conditions. If it satisfies, then you generate subsequent solutions. Otherwise, you go one step backward to check for another path.
 */

/*
 * Backtracking algorithm for hamiltonian cycle
 * Create an empty path array and add vertex 0 to it. Add other vertices, starting from the vertex 1. Before adding a vertex, check for whether it is adjacent to the previously added vertex and not already added. If we find such a vertex, we add the vertex as part of the solution. If we do not find a vertex then we return false.
 *
 */


# define V 5

bool isSafe(int v, bool graph[V][V], int path[], int pos)
{
    /* Check whether v is adjacent to the last vertex added in the path */
    if (graph[path[pos-1]][v] == 0) 
        return false;

    /* Check if the vertex has already been added in the path */
    for (int i=0; i < pos; i++)
        if (path[i] == v)
            return false;

    return true;
}

bool hamCycleUtil(bool graph[V][V], int path[], int pos)
{
    /* base case: If all vertices are included in Hamiltonian cycle */
    if (pos == V)
    {
        /* If there's an edge between the last added vertex to the first vertex in the path */
        if (graph[ path[pos-1] ][ [path[0] ] ] == 1)
            return true;
        else
            return false;
    }

    // Try different vertices as a next candidate in Hamiltonian cycle
    // don't try for 0 as 0 is used as starting point
    for (int v=1; v < V; v++)
    {
        if (isSafe(v, graph, path, pos)) 
        {
            path[pos] = v;

            /* recur to construct rest of the path */
            if (hamCycleUtil(graph, path, pos+1) == true)
                return true;

            /* If adding vertex v doesn't lead to a solution then remove it */
            path[pos] = -1;
        }
    }
}

bool hamCycle(bool graph[V][V])
{
    int *path = new int[V];
    for (int i = 0; i < V; i++)
        path[i] = -1;

    /* Let's put vertex 0 as the first vertex in the path. If there is a Hamiltonian Cycle, then the path can be started from any point of the cycle as the graph is undirected */
    path[0] = 0;
    if (hamCycleUtil(graph, path, 1) == false )
    {
        printf("\n Solution does not exist");
        return false;
    }

    printSolution(path);

    return true;
}

/* A utility function to print solution */
void printSolution(int path[]) 
{ 
    printf ("Solution Exists:"
            " Following is one Hamiltonian Cycle \n"); 
    for (int i = 0; i < V; i++) 
        printf(" %d ", path[i]); 
  
    // Let us print the first vertex again to show the complete cycle 
    printf(" %d ", path[0]); 
    printf("\n"); 
} 

// driver program to test above function 
int main() 
{ 
   /* Let us create the following graph 
      (0)--(1)--(2) 
       |   / \   | 
       |  /   \  | 
       | /     \ | 
      (3)-------(4)    */
   bool graph1[V][V] = {{0, 1, 0, 1, 0}, 
                      {1, 0, 1, 1, 1}, 
                      {0, 1, 0, 0, 1}, 
                      {1, 1, 0, 0, 1}, 
                      {0, 1, 1, 1, 0}, 
                     }; 
  
    // Print the solution 
    hamCycle(graph1); 
  
   /* Let us create the following graph 
      (0)--(1)--(2) 
       |   / \   | 
       |  /   \  | 
       | /     \ | 
      (3)       (4)    */
    bool graph2[V][V] = {{0, 1, 0, 1, 0}, 
                      {1, 0, 1, 1, 1}, 
                      {0, 1, 0, 0, 1}, 
                      {1, 1, 0, 0, 0}, 
                      {0, 1, 1, 0, 0}, 
                     }; 
  
    // Print the solution 
    hamCycle(graph2); 
  
    return 0; 
} 
