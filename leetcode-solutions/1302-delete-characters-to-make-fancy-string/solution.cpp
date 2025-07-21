class Solution {
public:
    string makeFancyString(string s) {
        string res;
        for (char c : s) {
            int len = res.length();
            if (len >= 2 && res[len - 1] == c && res[len - 2] == c) {
                continue; 
            }
            res += c;
        }
        return res;
    }
};
