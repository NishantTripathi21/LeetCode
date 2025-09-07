class Solution {
public:
    auto oddLen(int n) {
        vector<int>ans(n,0);
        int mid = n/2;
        int val = 0;
        int i= mid;
        int j= mid;
        while(i >= 0 && j < n) {
            ans[i]= val;
            ans[j]= (-1) * val;
            i--;
            j++;
            val++;
        }
        return ans;
    }
    auto evenLen(int n) {
        vector<int>ans(n,0);
        int mid = n/2;
        int val = 1;
        int i= mid-1;
        int j= mid;
        while(i >= 0 && j < n) {
            ans[i]= val;
            ans[j]= (-1) * val;
            i--;
            j++;
            val++;
        }
        return ans;
    }
    vector<int> sumZero(int n) {
        // if(n & 1) {
        //     return oddLen(n);
        // }
        // return evenLen(n);
        vector<int> ans;
        for (int i = 1; i <= n / 2; ++i) {
            ans.push_back(i);
            ans.push_back(-i);
        }
        if (n % 2 == 1) {
            ans.push_back(0);
        }
        return ans;
    }
};
