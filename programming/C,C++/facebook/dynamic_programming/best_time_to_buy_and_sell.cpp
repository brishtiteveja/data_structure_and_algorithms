#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void print(vector<int>& v) {
        int i;
        for(i=0; i<v.size(); i++) {
            cout << v[i] << " ";
        }
        cout << endl;
        
        return;
    }
    
    void print2(vector<vector<int> >& v) {
        int i, j;
        for(i=0; i<v.size(); i++) {
            for(j=0; j<v[i].size(); j++) {
                cout << v[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        
        return;
    }
    
    int maxProfit(vector<int>& prices, int n) {
        int pn = prices.size();
        
        if (pn == 0)
            return 0;
        
        vector<vector<int> > T(n+1, vector<int>(pn+1));
        
        /*              j
                  0   1  2  3  4
                 p1 p2 p3 p4 p5
     i   0    0   0  0  0  0    
         1 t1 0 
         2 t2
         
         //  Either no transaction or
         //  Check Buy on m-th day, sell on j-th day + already earned profit till i-th transaction
         T[i][j] = max{T[i-1][j],  prices[j] - prices[m] + T[i-1][j] }  0 <= m <= j
         
        */
        
        int i, j;
        for(i=0; i<=n; i++)
            T[i][0] = 0;
        
        for(j=0; j<=pn; j++)
            T[0][j] = 0;
        
        
        int di = INT_MIN;
        int max_profit = INT_MIN;
        for(i=1; i<=n; i++) {
            for(j=1; j<=pn; j++) {
                int mx = INT_MIN;
                int m;
                for(m=0; m<j; m++) {
                    int pr = prices[j-1] - prices[m] + T[i-1][j];
                    if (pr > mx) {
                        mx = pr;
                        di = m; // save the day index
                    }
                }
                mx = max(T[i-1][j], mx);
                T[i][j] = mx;
                
                // update max profit
                if (mx > max_profit)
                    max_profit = mx;
            }
        }
        

        print2(T);
        
        return max_profit;
    }
};

int main()
{
    int p[6] = {7,1,5,3,6,4};
    vector<int> prices(p, p+6); 

    Solution sol;
    int m = sol.maxProfit(prices, 5);
    cout << m << endl;

}

