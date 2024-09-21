class Solution {
public:
    bool usingRec(string& s, unordered_set<string>&wordSet, int start,unordered_map<int, bool>& memo){
        if(start >= s.size()){
            return true;
        }
        if(memo.find(start) != memo.end())return memo[start];
        for(int end= start+1; end <= s.size();end++){
            string temp=s.substr(start,end-start);
            if(wordSet.find(temp) != wordSet.end()){
                if(usingRec(s,wordSet,end,memo)){
                    memo[start]=true;
                    return true;
                }
                
            }
        }
        memo[start]=false;
        return false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>wordSet(wordDict.begin(),wordDict.end());
        unordered_map<int, bool> memo;
        return usingRec(s,wordSet,0,memo);
        
    }
}; 
