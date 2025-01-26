class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> stk;
        
        for (char ch : s) {
            if (ch == '(') {
                stk.push(0);
            }
            else {
                int inner_score = 0;
                while (!stk.empty() && stk.top() != 0) {
                    inner_score += stk.top(); 
                    stk.pop();
                }
                stk.pop();
                stk.push(inner_score == 0 ? 1 : 2 * inner_score);
            }
        }
        
        int result = 0;
        while (!stk.empty()) {
            result += stk.top();
            stk.pop();
        }
        return result;
    }
};
