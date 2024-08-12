class Solution {
public:
    void buildans(string &ans,stack<string>&st){
        if(st.empty())return;
        string minpath=st.top();st.pop();
        buildans(ans,st);
        ans+=minpath;
    }
    string simplifyPath(string path) {
        // single slash-ignore
        // slash dot- continue
        // slash double dot-one step back{pop}
        stack<string>st;
        int i=0;
        while(i<path.size()){
            int start=i;
            int end =i+1;
            while(end<path.size()&& path[end]!='/'){
                ++end;
            }
            string minpath=path.substr(start,end-start);
            i=end; 
            if(minpath=="/" ||  minpath=="/."){
                continue;
            }
            else if(minpath!="/.."){
                st.push(minpath);
            }
            else if(!st.empty()){
                st.pop();
            }
            
        }
        string ans=st.empty()?"/":"";
        buildans(ans,st);
        return ans;
    }
};
