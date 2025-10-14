class Solution {
public:
    int countBinarySubstrings(string s) {
        vector<int> ans;
        int index = 0;
        while (index < s.size()) {
            int count = 0;
            if (s[index] == '0') {
                while (index < s.size() && s[index] == '0') {
                    count++;
                    index++;
                }
            }

            else
                while (index < s.size() && s[index] == '1'){
                    count++;
                    index++;
                }

            ans.push_back(count);
        }

        int result = 0;
        for (int i = 0; i < ans.size() - 1; i++) {
            result += min(ans[i], ans[i + 1]);
        }

        return result;
    }
};
