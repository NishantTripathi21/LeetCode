class Solution {
public:
    string lexSmallest(string s) {
        string ans = s;
        int n = s.size();
        for (int k = 1; k <= n; k++) {
            string t1 = s, t2 = s;
            reverse(t1.begin(), t1.begin() + k);
            ans = min(ans, t1);
            reverse(t2.end() - k, t2.end());
            ans = min(ans, t2);
        }
        return ans;
    }
};
