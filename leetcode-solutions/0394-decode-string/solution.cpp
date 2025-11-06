class Solution {
public:
    string decodeString(string s) {
        
        stack<string> st;
        for(int i= 0; i< s.size(); i++) {
            char ch = s[i];
            if(isdigit(ch)) {
                string num = "";
                while(isdigit(s[i])) {
                    num += s[i];
                    i++;
                }
                i--;
                st.push(num);
            }
    
            else if(isalpha(s[i]) || ch == '[') {
                string str(1,ch);
                st.push(str);
            }
            else if(ch == ']') {
                string str = "";
                while(!st.empty() && st.top() != "[") {
                    str += st.top();
                    st.pop();
                }
                if(!st.empty() && st.top() == "[")st.pop();

                string num = "";
                while(!st.empty() && all_of(st.top().begin(),st.top().end(),:: isdigit)) {
                    num = st.top();
                    st.pop();
                }
                //cout<<"num"<<num;
                //reverse(num.begin(), num.end());
                int n = stoi(num);
                string abc = "";
                while(n--) {
                    abc += str;
                }
                st.push(abc);
            }

        }
        string ans = "";
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
