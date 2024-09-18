class Solution {
public:
    bool isPalindrome(string s, int index, int i){
        int start= index;
        int end=i;
        while(start <= end){
            if(s[start] != s[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    void print(vector<string>&s){
        for(auto i:s){
            cout<<i<<" ";
        }
    }
    void usingRec(string& s,vector<vector<string>>&ans,vector<string>&temp,int index){
        if(index==s.size()){
            print(temp);
            ans.push_back(temp);
            return;
        }
        for(int end=index;end<s.size();end++){
            if(isPalindrome(s,index,end)){
                temp.push_back(s.substr(index, end-index+1));
                usingRec(s,ans,temp,end+1);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>temp;
        usingRec(s,ans,temp,0);
        return ans;
    }
};
