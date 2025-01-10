class Solution {
public:
    vector<string> trial( vector<string>& words1, vector<string>& words2 ){
        int left = 0;
        int right = 0;
        vector<string> ans;
        vector<int> mp(26,0);
        for( string s: words2){
            vector<int>abc(26,0);
            for( char ch:s){
                abc[ch -'a']++;
                mp[ch-'a'] = max(mp[ch-'a'],abc[ch-'a']);
            }
        }
        for( string s: words1){
            vector<int>abc(26,0);
            for( char ch: s){
                abc[ch - 'a']++;
            }
            if( compare(abc,mp)){
                    ans.push_back(s);
                }
        }
        return ans;
    }
    bool compare( vector<int>& abc,vector<int>& mp){
        for( int i= 0; i< 26; i++){
            if(mp[i] > abc[i]){
                return false;
            }
        }
        return true;
    }
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        return trial(words1,words2);
    }
};
