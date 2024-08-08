class Solution {
public:
    bool isValid(string s) {
          // Stack to keep track of opening brackets
            stack<char> stack;
            // Map to hold the matching pairs
            unordered_map<char, char> matchingBracket = {{')', '('}, {'}', '{'}, {']', '['}};
            
            // Iterate through each character in the string
            for (char c : s) {
                // If it's a closing bracket
                if (matchingBracket.count(c)) {
                    // Pop the top element from the stack if it's not empty; otherwise, assign a dummy value
                    char topElement = !stack.empty() ? stack.top() : '#';
                    stack.pop();
                    // Check if the popped element matches the corresponding opening bracket
                    if (topElement != matchingBracket[c]) {
                        return false;
                    }
                } else {
                    // It's an opening bracket, push onto the stack
                    stack.push(c);
                }
            }
            
            // If the stack is empty, all brackets were properly matched
            return stack.empty(); 
    }
};
