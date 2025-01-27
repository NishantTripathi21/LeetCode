class Solution {
public:
    string smallestSubsequence(string s) {
        stack<char>st;
        vector<bool>taken(26,false);
        int lastSeen[26];
        for( int i = 0; i< s.size(); i++) {
            lastSeen[s[i]-'a']= i;
        }
        for( int i= 0; i< s.size(); i++) {
            char ch = s[i];
            if( taken[ch-'a'])continue;
            while(!st.empty() && ch < st.top() && lastSeen[st.top()-'a'] > i) {
                taken[st.top()-'a'] = false;
                st.pop();
            } 
            st.push(ch);
            taken[st.top()-'a'] = true;
        }
        string result;
        while( !st.empty()){
            result += st.top();
            st.pop();
        }
        reverse(result.begin(),result.end());
        return result;
    }
};
