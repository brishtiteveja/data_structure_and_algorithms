#include <iostream>
#include <vector>

using namespace std;

class KnapSack
{
    private:
        int **K;
        int W, n; // weight constraint

        vector<int> w, v;

        int max(int a, int b)
        {
            return a>=b? a:b;
        }

    public:
        KnapSack(vector<int> weight, vector<int> val, int Wg) 
        {
            w = vector<int>(weight.begin(), weight.end());
            v = vector<int>(val.begin(), val.end());

            n = v.size();
            W = Wg;

            K = new int*[v.size()+1];
            for (int i=0; i<= v.size(); i++)
                K[i] = new int[w.size()+1];
        }

        void populateKnapSack()
        {
            int i, wg;

            // The sack has no capacity
            for(i=0; i<=n; i++) 
            {
                K[i][0] = 0;
            }

            // No item is taken in a sack
            for(wg=0; wg<=W; wg++)
            {
                K[0][wg] = 0;
            }

            for(i=1; i<=n; i++) // i-th item to be taken 
            {
                for(wg=1; wg<=W; wg++) // capacity of the knapsack
                {
                    // weight of i-th object
                    int wgt = w[i-1];
                    // value of i-th object
                    int vi = v[i-1];

                    int maxv; 

                    // if i-th item is not taken
                    maxv = K[i-1][wg];

                    // if the i-th object is taken
                    if (wg-wgt>=0) 
                    {
                        maxv = vi + K[i-1] [wg-wgt];
                        // compare with if not taken
                        maxv = max(K[i-1][wg], maxv);
                    }
            

                    K[i][wg] = maxv;
                }
            }
        }

        void printKnapSackTable()
        {
            int i, wg;

            for(i=0; i<=n; i++) // i-th item to be taken 
            {
                for(wg=0; wg<=W; wg++) // capacity of the knapsack
                {
                    printf("%2d  ", K[i][wg]);
                }
                cout << endl;
            }

        }

        int getMaxValue()
        {
            return K[n][W];
        }

        void printKnapSackItem()
        {
            vector<int> item;

            int i = n;
            int wg = W;
                    
            cout << "i = " << i << " w = " << wg << endl;
            cout << endl;

            while(wg > 0 && i > 0) 
            {
                // if i-th item is taken
                if (K[i][wg] != K[i-1][wg])
                {
                    item.push_back(i);
                    // subtract the weight of i-th item
                    wg = wg - w[i-1];
                } 

                i--; // reduce item
            }

            reverse(item.begin(), item.end());

            for(i=0; i<item.size(); i++)
            {
                cout << item[i] << " ";
            }

            cout << endl;

        }
};


int main()
{
    int n = 5;
    int v[5] = {1, 3, 5, 2, 7};
    int w[5] = {2, 4, 3, 1, 5};

    int W = 7;

    vector<int> val(v, v+n); 
    vector<int> weight(w, w+W);

    KnapSack KS(weight, val, W);

    KS.populateKnapSack();
    KS.printKnapSackTable();
    cout << KS.getMaxValue() << endl;
    KS.printKnapSackItem();

    return 0;

}
