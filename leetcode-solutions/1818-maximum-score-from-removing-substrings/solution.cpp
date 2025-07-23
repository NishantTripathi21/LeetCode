class Solution {
public:
    int score = 0;
    void removeAB(string& s, int x) {
        stack<char>st;
        int index = 0;
        while(index < s.size()) {
            char ch = s[index];
            if(st.empty()) {
                st.push(ch);
                index++;
                continue;
            }
            char top = st.top();
            if(ch == 'b' && top == 'a') {
                st.pop();
                score += x;
            }
            else{
                st.push(ch);
            }
            index++;
        }
        string temp = "";
        while(!st.empty()) {
            temp += st.top();
            st.pop();
        }
        reverse(temp.begin(),temp.end());
        s = temp;
    }
    void removeBA(string& s, int y) {
        stack<char>st;
        int index = 0;
        while(index < s.size()) {
            char ch = s[index];
            if(st.empty()) {
                st.push(ch);
                index++;
                continue;
            }
            char top = st.top();
            if(ch == 'a' && top == 'b') {
                st.pop();
                score += y;
            }
            else{
                st.push(ch);
            }
            index++;
        }
        string temp = "";
        while(!st.empty()) {
            temp += st.top();
            st.pop();
        }
        reverse(temp.begin(),temp.end());
        s = temp;
    }
    int maximumGain(string s, int x, int y) {
        if(x>y){
            removeAB(s,x);
            removeBA(s,y);
        }
        else{
            removeBA(s,y);
            removeAB(s,x);
        }
        //cout<<s;
        return score;
    }
};
