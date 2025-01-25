class Solution {
public:
    string removeOuterParentheses(string s) {
        int count = 0;
        int index = 0;
        string result;
        while( index < s.size()){
            char ch = s[index];
            if( ch == '('){
                count++;
            }
            if( count > 1){
                result += ch;
            }
            if( ch == ')'){
                count--;
            }
            index++;
        }
        return result;
    }
};
