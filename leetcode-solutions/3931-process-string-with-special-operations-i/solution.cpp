class Solution {
public:
    string processStr(string s) {
        string result ="";
        for(int i= 0; i< s.size(); i++) {
            char ch = s[i];
            if(ch == '*') {
                if(result.size() >= 1) result.pop_back();
            }
            else if( ch == '#') {
                result += result;
            }
            else if( ch == '%') {
                reverse(result.begin(),result.end());
            }
            else{
                result += ch;
            }
        }
        return result;
    }
};
