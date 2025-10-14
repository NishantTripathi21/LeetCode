class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;

        int index = 0;
        while(index<s.size()){
            string word = "";
            
            while(s[index] == ' ') index++;

            while(index < s.size() && s[index] != ' ') word.push_back(s[index++]);
            if(!word.empty())
            st.push(word);
        }
        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
            if(!st.empty()) ans.push_back(' ');
        }

        return ans;
    }
};
