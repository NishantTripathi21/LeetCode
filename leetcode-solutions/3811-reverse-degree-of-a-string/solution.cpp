class Solution {
public:
    int reverseDegree(string s) {
        int ans = 0;
        for(int i = 0;  i< s.size(); i++) {
            int reversed_position = 26 - (s[i] - 'a');
            ans += reversed_position * (i+1);
        }
        return ans;
    }
};
