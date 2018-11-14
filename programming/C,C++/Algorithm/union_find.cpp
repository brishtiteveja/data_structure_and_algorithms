class Solution {
    public:
        bool Union(int x, int y, vector<int>& parents)
        {
            if (x > y)
                Union(y, x, parents);

            int px = Find(x, parents);
            int py = Find(y, parents);

            parents[py] = px;

            return true;
        }

        bool Find(int x, const vector<int> &parents) {
            return x == parents[x] ? x: Find(parents[x], parents);
        }

        void validTree(int n, vector<pair<int, int> >& edges) {
            if (n == 0) 
                return true;
            if (edges.size() != n-1)
                return false;

            vector<int> parents(n, 0);
            for(int i=0; i<n; i++)
                parents[i] = i;

            int cnt = n; // (n-1) disjoint set

            for(int i=0; i<edges.size(); i++)
                if(Union(edges[i].first, edges[i].second, parents)
                    cnt--;

            return cnt == 1; // for a tree there will be a single disjoint set, there's no cycle
        }
};
