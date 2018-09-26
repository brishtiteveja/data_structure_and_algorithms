#include <iostream>
#include <queue>

using namespace std;

class qcompare
{
    bool reverse;
    public:
        // constructor
        qcompare(bool rev=false)
        {
            reverse = rev;
        }

        bool operator()(const int &lhs, const int &rhs)
        {
            if(reverse)
                return lhs < rhs;
            else
                return lhs > rhs;
        }
};

int main()
{
    int a[10] = {1, 4, 5, 2, 3, 7, 8, 6, 10, 9};

    priority_queue<int, vector<int>, qcompare > pq;

    int i;
    for(i=0; i<10; i++)
    {
        pq.push(a[i]);
    }

    while(!pq.empty())
    {
        int e = pq.top();
        cout << e << " "; 
        pq.pop();
    }
    cout << endl;

    return 0;
}

