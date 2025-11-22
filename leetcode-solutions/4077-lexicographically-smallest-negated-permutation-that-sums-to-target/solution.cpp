class Solution {
public:
    vector<int> lexSmallestNegatedPerm(int n, long long target) {
        long long S = 1LL * n * (n + 1) / 2;
        if (llabs(target) > S) return {};
        if (((S - target) & 1)) return {};
        long long sn = (S - target) / 2;
        vector<bool> neg(n + 1, 0);
        int i = n;
        while(i >= 1 && sn > 0) {
            if(sn >= i) {
                neg[i] = 1;
                sn -= i;
            }
            i--;
        }
        if (sn != 0) return {};
        vector<int> ans;
        int j = 1;
        while (j <= n) {
            if (neg[j]) {
                ans.push_back(-j);
            }   
            else ans.push_back(j);
            j++;
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
