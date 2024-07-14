class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int hash[267]={0};//mapping each charector of "s" with "t"
        bool ismapped[267]={0};//checking if charector is already mapped or not
        for(int i=0;i<s.size();i++){
            if(!hash[s[i]] && !ismapped[t[i]]){
            hash[s[i]]=t[i];
            ismapped[t[i]]=true;
            }
        }
        for(int i=0;i<s.size();i++){
            if(hash[s[i]]!=t[i]){
                return false;
            }
        }
        return true;

    }
};
