class Solution {
public:
    inline long long pali(long long val, long long mid=-1){
        long long ans = val;
        if(mid != -1)
            ans = ans * 10 + mid;
        for(; val; val /= 10)
            ans = ans * 10 + val % 10;
        return ans;
    }
    inline bool is_pali(long long val, long long l, long long r){
        if(val < l || val > r)
            return false;
        long long t = 0;
        for(auto v = val; v; v/=10)
            t = t*10 + v % 10;
        return t == val;
    }
    int superpalindromesInRange(string L, string R) {
        long long l = stoll(L), r = stoll(R);
        int ans = (l <= 1 && 1 <= r) + (l <= 4 && 4 <= r) + (l <= 9 && 9 <= r);
        for(long long i = 1; i < 34000; i++){
            auto val = pali(i);
            if(val * val > r) break;
            for(int m = -1; m < 10; ++m){
                val = pali(i, m);
                if(is_pali(val * val, l, r))
                    ans += 1;
            }
        }
        return ans;
    }
};
