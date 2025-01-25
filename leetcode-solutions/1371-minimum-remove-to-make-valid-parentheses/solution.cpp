class Solution {
public:
    string method1( string s) {
        stack<int>st;
        unordered_set<int>remove;
        int index = 0;
        while( index < s.size()){
            char ch = s[index];
            if( ch == '('){
                st.push(index);
            }
            else if ( ch == ')'){
                if( st.empty()){
                    remove.insert(index);
                }
                else{
                    st.pop();
                }
            }
            index++;
        }
        while( !st.empty()){
            remove.insert(st.top());
            st.pop();
        }
        string result;
        index = 0;
        while( index < s.size()){
            if( remove.find(index) != remove.end()){
                index++;
                continue;
            }
            else{
                result += s[index++];
            }
        }
        return result;
    }
    string minRemoveToMakeValid(string s) {
        return method1(s);
    }
};
