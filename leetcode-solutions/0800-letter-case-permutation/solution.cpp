class Solution {
public:
    set<string>ans;
    void solve(string s, int index) {
        if(index >= s.size()){
            ans.insert(s);
            return;
        }
        s[index] = toupper(s[index]);
        solve(s,index+1);
        s[index] = tolower(s[index]);
        solve(s,index+1);
    }
    vector<string> letterCasePermutation(string s) {
        solve(s,0);
        vector<string>result;
        for(auto it: ans){
            result.push_back(it);
        }
        return result;
    }
};
