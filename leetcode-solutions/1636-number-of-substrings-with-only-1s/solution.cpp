class Solution {
public:
    int numSub(string s) {
        int left = 0, right = 0;
        int z = 0;
        int MOD = 1e9+7;
        int o = 0;
        int n = s.size();
        long long count = 0;
        while( right < n) {
            char ch = s[right];
            if(ch == '0') {
                right++;
                left = right;
                continue;
            }
            count += (long long)(right- left + 1)%MOD;
            right++;
        }
        return (count)%MOD;
    }
};
