class Solution {
public:
    int calculate(string s) {
        stack<int> stack;
        int num = 0, result = 0;
        char sign = '+';
        
        for (int i = 0; i < s.size(); ++i) {
            char ch = s[i];

            if (isdigit(ch)) {
                num = num * 10 + (ch - '0');
            }
            
            if ((!isdigit(ch) && ch != ' ') || i == s.size() - 1) {
                if (sign == '+') {
                    stack.push(num);
                }
                else if (sign == '-') {
                    stack.push(-num);
                }
                else if (sign == '*') {
                    int top = stack.top();
                    stack.pop();
                    stack.push(top * num);
                }
                else if (sign == '/') {
                    int top = stack.top();
                    stack.pop();
                    stack.push(top / num);
                }
                sign = ch;
                num = 0;
            }
        }

        while (!stack.empty()) {
            result += stack.top();
            stack.pop();
        }
        
        return result;
    }
};
