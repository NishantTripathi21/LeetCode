class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>st;
        for(int i=0;i<num.size();i++){
            if(k>0){
                while(!st.empty()&&num[i]<st.top()){
                st.pop();
                k--;
                if(!k)break;
                }
            }
            st.push(num[i]);
        }
        if(k>0){
            while(!st.empty()&& k){
                st.pop();
                k--;
            }
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        while(ans.size()>0 && ans.back()=='0'){
            ans.pop_back();
        }
        reverse(ans.begin(),ans.end());
        if(!ans.size())return "0";
        return ans;    
    }
};
