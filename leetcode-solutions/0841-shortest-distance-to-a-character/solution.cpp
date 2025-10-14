class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> ans(s.size(), 0);
        int distance = -1;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == c)
                distance = 0;
            else if (distance == -1) {
                ans[i] = INT_MAX;
                continue;
            } else
                distance++;

            ans[i] = distance;

        }
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == c)
                distance = 0;
            else if (distance == -1)
                continue;
            else
                distance++;
            ans[i] = min(ans[i], distance);
        }

        return ans;
    }
};
