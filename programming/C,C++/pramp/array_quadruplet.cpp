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

vector<int> findArrayQuadruplet(vector<int> arr, int s)
{
    int n = arr.size();

    vector<int> res(0);

    // If there are fewer than 4 items in arr, by definition no quadruplet exists whose sum is s
    if (n < 4)
        return res;

    sort(arr.begin(), arr.end());

    int i, j;
    for(i=0; i<=n-4; i++)
    {
        for(j=i+1; j<=n-3; j++)
        {
            int r = s - (arr[i] + arr[j]);

            int low, high;
            low = j+1, high = n-1;

            while (low < high)
            {
                // if the sum is lower than r, then increase the low
                if (arr[low] + arr[high] < r)
                {
                    low++; 
                // if the sum is greater than r, then decrease the low
                } else if (arr[low] + arr[high] > r)
                {
                    high--;
                }
                else
                {
                    res.push_back(arr[i]);
                    res.push_back(arr[j]);
                    res.push_back(arr[low]);
                    res.push_back(arr[high]);
                    return res;
                }
            }
        }
    }

    return res;
}

int main() {
    int n = 8;
    int a[8] = {2, 7, 4, 0, 9, 5, 1, 3}; 
    int s = 20;
  
    vector<int> arr(a, a+n);
    A = vector<int> (arr.begin(), arr.end());
    print(arr);
    sort(arr.begin(), arr.end()); 
    // 9 7 5 4 3 2 1 0
    print(arr);
    cout << endl;

    vector<int> res;
    res = findArrayQuadruplet(arr, s);
    print(res);
  
  return 0;
}
