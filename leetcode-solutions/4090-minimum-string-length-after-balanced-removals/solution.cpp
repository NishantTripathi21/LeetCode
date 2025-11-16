class Solution {
public:
    int minLengthAfterRemovals(string s) {
        string ans = "";
        for(int i= 0; i< s.size(); i++ ) {
            if(!ans.empty() && ans.back() != s[i]) {
                ans.pop_back();
            }
            else {
                ans += s[i];
            }
        }
        int n = ans.size();
        return n;
     }
};
