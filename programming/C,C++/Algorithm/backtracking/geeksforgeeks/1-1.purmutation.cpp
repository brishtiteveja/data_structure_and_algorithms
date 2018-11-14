#include <iostream>
#include <vector>

#define FOR(i, n) for(int i=0; i<n; i++)

using namespace std;


void print_res(vector<vector<int> >& res) {
    cout << res.size() << endl;

    int i, j;
    FOR(i, res.size()) {
        FOR(j, res[i].size() ) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return;
}

void make_permutation(int s, vector<int>& chosen, vector<int>& v, vector<vector <int> >& res) {
    if (s == v.size()) {
        int k;
        vector<int> r;
        // chosen has the index for the current permutation
        FOR(k, chosen.size())
            r.push_back(v[chosen[k]]);

        res.push_back(r);

        return;
    }

    int i;

    FOR(i, v.size() ){
        // check whether i is already chosen
        int j;
        bool used = false;
        FOR(j, chosen.size()) {
            if (chosen[j] == i) {
                used = true;
                break;
            }
        }
        if (used)
            continue;

        chosen.push_back(i);
        make_permutation(s+1, chosen, v, res);
        chosen.pop_back();
    }
}

void make_all_possible(int s, vector<int>& v, vector<vector<int> > &res) {
    if (s == v.size()) {
        res.push_back(v);
        return;
    }

    int i;
    FOR(i, v.size()) {
        // swap v[s] and v[i]
        int tmp = v[s];
        v[s] = v[i];
        v[i] = tmp;

        make_all_possible(s+1, v, res); 

        // swap back, backtracking
        tmp = v[s];
        v[s] = v[i];
        v[i] = tmp;
    }

    return;
}


void permute(vector<int>& v, vector<vector<int> > &res)
{
    
    if (v.empty())
        return;

    vector<int> chosen;
    make_permutation(0, chosen, v, res);

    return;
}


int main()
{
    int n = 3;
    int a[] = {1, 2, 3};
    
    vector<int> v(a, a+n);

    vector<vector<int> > res;
    permute(v, res);

    print_res(res);

    return 0;
}
