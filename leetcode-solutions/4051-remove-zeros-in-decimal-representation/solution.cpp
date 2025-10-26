class Solution {
public:
    long long removeZeros(long long n) {
        string s = to_string(n);
        string ans = "";
        for(int i= 0; i< s.size();  i++) {
            char ch = s[i];
            if(ch != '0') {
                ans += ch;
            }
        }
        return stoll(ans);
    }
};
