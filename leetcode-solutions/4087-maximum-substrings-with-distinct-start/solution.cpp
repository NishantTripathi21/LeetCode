class Solution {
public:
    int maxDistinct(string s) {
        set<int>st;
        for(char ch: s) {
            int i = ch - 'a';
            st.insert(i);
        }
        return (int)st.size();
    }
};
