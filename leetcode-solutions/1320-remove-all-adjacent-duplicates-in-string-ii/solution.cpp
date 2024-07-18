class Solution {
public:
    bool last_k_1_charSame(string& ans,int& k,char& newch){
        int index=ans.size()-1;
        for(int i=0;i<k-1;i++){
            if(newch!=ans[index--]) return false;
        }
        return true;
    }
    string removeDuplicates(string s, int k) {
        string ans;
        for(int i=0;i<s.size();i++){
            char& newch=s[i];
            if(ans.size()<k-1){
                ans.push_back(newch);
            }
            else{
                if(last_k_1_charSame(ans,k,newch)){
                    for(int j=0;j<k-1;j++){
                        ans.pop_back();
                    }
                }
                else{
                    ans.push_back(s[i]);
                }
            }
        }
        return ans;
        
    }
};
