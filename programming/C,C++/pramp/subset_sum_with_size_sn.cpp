#include <iostream>
#include <vector>

using namespace std;
/*
input:  arr = [2, 7, 4, 0, 9, 5, 1, 3], s = 9

peer: Byung Chul A.
https://www.linkedin.com/in/byung-chul-an-8a71b23/
abcgreat@gmail.com

        DP equation:
          a) base case: dp[i][0] = T 
          b) dp[i][j] =    dp[i-1][j] & dp[i-1][j-arr[i]]

                               j
             id   arr  0 1 2 3 4 5 6 7 8 9    
                       T F F F F F F F F F  <-- No element taken 
              0    0   T F F F F F F F F F  
              1    2   T F T F F F F F F F   
              2    3   T F T T F T F F F F       
              3    4   T F T T T T T T F F       
              4    7   T F T T T T T T F T         
              5    9   T F T T T T T T F T           
                    
Code by peer: 
------------
      for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
        {
          left = j + 1
          right = n - 1
          
          while(left < right)
          {
            
            if bigger than I am looking for?
             right--
            else
             left++
          }
        }

*/
vector<vector<bool> > T; 
vector<int> A;

void print(vector<int> v)
{
    for(int i=0; i<v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

void printTable(vector<int> arr, int n, int s)
{
    int i,j;

    printf(" i  A   ");
    for(j=0; j<=s; j++)
    {
        printf("%2d ", j);
    }
    printf("\n");

    for(i=0; i<=n; i++)
    {
        for(j=0; j<=s; j++)
        {
            if (j==0)
            {
                if (i==0)
                    printf("      | ");
                else
                    printf("%2d %2d | ", i-1, arr[i-1]);
            }

            if (T[i][j])
                printf(" T ");
            else 
                printf(" F ");
        }
        printf("\n");
    }

  return;
}

vector<int> findSubset(int i, int s, int en, int sn)
{
    vector<int> res;

    // Base case for returning empty vector 
    if (s==0)
        return res;

    if (en >= sn) // greater than desired number of elements
        return res;
    if (i <= 0) 
        return res;

    vector<int> res1, res2;
    // if by taking i-th element we can make sum s
    // then take i-th element, then check whether previous elements can form sum s-arr[i]
    //
    vector<int> tres = res;
    if (T[i][s] == T[i-1][s-A[i-1]])
    {
        res.push_back(A[i-1]);
        res1 = findSubset(i-1, s-A[i-1], en + 1, sn); // increase the element number
        //print(res1);

        if (res1.size() > 0)
        {
            cout << "1. i = " << i-1 <<  " A[i] = " << A[i-1] << " s = " << s << endl;
            res.insert(res.end(), res1.begin(), res1.end());
        }
    }
    if(en == 0 && res.size() > 0)
    {
        cout << endl;
        cout << "Final1" << endl;
        print(res);
    }

    // if by not taking i-th element we can make sum s
    // then don't take i-th element
    if (T[i][s] == T[i-1][s])
    {
        //cout << "i = " << i << " s = " << s << endl;
        res2 = findSubset(i-1, s, en, sn);
        //print(res2);
        if (res2.size() > 0)
        {
            cout << "2. i = " << i-1 << " s = " << s << endl;
            cout << endl;
            tres.insert(tres.end(), res2.begin(), res2.end());
        }
    }

    if(en == 0 && tres.size() > 0)
    {
        cout << endl;
        cout << "Final2" << endl;
        print(tres);
        tres.clear();
    }

    
    return res;
}

vector<int> findSubsetWithSize(const vector<int> &arr, int s, int sn) 
{
    int n = arr.size();
    T = vector<vector<bool> > (n+1, vector<bool>(s+1)); // T[n][s] : Can we make the sum equals s by using up to (n-1)-th element?
  
    int i,j; // i: upto element i;  j: sum j

    T[0][0] = true; // can make sum 0 by not taking any element
    for(i=0; i<=n; i++)
    {
        T[i][0] = true; // by not taking element we can always keep the sum 0
    }

    for(j=1; j<=s; j++)
    {
        T[0][j] = false; // can't make the sum j by not taking any element 
    }
  
    // Populate DP table
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=s; j++)
        {
            bool a=false, b=false;

            a = T[i-1][j]; // Can I make the sum to be j by not including the arr[i] element ?
            if(j-arr[i-1] >= 0)
            {
                b = T[i-1][j-arr[i-1]]; // Can I include the arr[i] and then see whether a solution for j-arr[i] already exists 
            }

            T[i][j] = a | b; // if either way I can make the sum to be j, then make (i,j)-th entry to be true
        }
    }
 
    printTable(arr, n, s);
 
    vector<int> res;

    // print out the first solution in ascending order
    // this was the reason of initially sorting the array in decreasing order
    int en; // element number to check quadruplet

    // initialize
    i = n, j=s;
    for(; i> 0 && j>=0; ) {
        if(j-arr[i-1] >= 0 && T[i][j-arr[i-1]]) {  
            res.push_back(arr[i-1]);
            j = j-arr[i-1];
            i--;
        } else if (T[i][j]) 
        {
            i--;
        } 
  }
  print(res); 


  cout << "Start" << endl;
  findSubset(n, s, 0, sn); 
  
  return res;
  
}

class comp
{
    bool rev;
    public:
        comp(bool revp=false) 
        {
            rev = revp;
        }

        bool operator()(int l, int r)
        {
            if(rev)
                return l>r;
            else
                return l<r;
        }
};

int main() {
    int n = 8;
    int a[8] = {2, 7, 4, 0, 9, 5, 1, 3}; 
    int s = 20;
    int sn = 4; // quadruplet
  
    vector<int> arr(a, a+n);
    A = vector<int> (arr.begin(), arr.end());
    print(arr);
    sort(arr.begin(), arr.end(), comp(true)); 
    // 9 7 5 4 3 2 1 0
    print(arr);
    cout << endl;

    findSubsetWithSize(arr, s, sn);
  
  return 0;
}
