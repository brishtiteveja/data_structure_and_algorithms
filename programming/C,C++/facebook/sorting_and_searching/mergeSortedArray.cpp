#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void quicksort(vector<int>& v) 
    {
        // take a pivot
        // put elements less than pivot in the left
        // put elements greater than pivot in the right
        // then recursively sort the left and right 
    }
    
    void swap(int &a, int &b) 
    {
        int temp = b;
        b = a;
        a = temp;
        
        return;
    }
    
    void print(vector<int>& v, int l, int r)
    {
        int i;
        for (i=l; i<=r; i++)
            cout << v[i] << " ";
        
        cout << endl;
    }
    
    void merge(vector<int>& v, int l, int m, int r)
    {
        // now merge
        vector<int> buf;
        int i, j, b;
        for(i=l; i<=m; i++)
            buf.push_back(v[i]);
              
        for(b=0,i=l, j=m+1; b < buf.size() && j<= r;)
        {
            // 1 4 7    2 5 5 6
                
            if(buf[b] <= v[j])
            {
                v[i] = buf[b];
                b++;
                i++;
            }
                
            if(v[j] < buf[b]) {
                v[i] = v[j];
                j++;
                i++;
            }
        }
            
        for(; b < buf.size(); b++, i++)
            v[i] = buf[b];
            
        for(; j <= r; j++, i++)
            v[i] = v[j];
        
        return;
    }
    void partitionAndMerge(vector<int>& v, int l, int r) {
        //partition the vec into two equal sub vec
        //then merge
        // when merging merge in a sorted way
        
        if (l < r) {    
            int m = l + (r-l)/2;
            partitionAndMerge(v, l, m);
            partitionAndMerge(v, m+1, r);
            
            merge(v, l, m, r);
        }
        
        return;
    }
    
    void mergesort(vector<int>& v) {
        partitionAndMerge(v, 0, v.size()-1);
    }
    
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i,j;
        
        for(i=m, j=0; j < n; i++, j++ ) 
        {
            nums1[i] = nums2[j];
        }
        
        print(nums1, 0, nums1.size()-1);
        mergesort(nums1);
        print(nums1, 0, nums1.size()-1);
        
        return;
    }
};

int main()
{
    int m = 3;
    int v1[6] = {1, 2, 3, 0, 0, 0};
    
    int n = 3;
    int v2[3] = {2, 5, 6};

    vector<int> nums1(v1, v1+6);
    vector<int> nums2(v2, v2+n);

    Solution sol;
    sol.merge(nums1, m, nums2, n);
    
    return 0;
}
