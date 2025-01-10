class Solution {
public:
    bool allzero( int hash[],int n = 26){
        for( int i = 0; i< n; i++){
            if( hash[i] != 0){
                return false;
            }
        }
        return true;
    }
    vector<int> method( string s, string p){
        int right = 0;
        int left = 0;
        int m = p.size();
        vector<int>ans;
        int hash[26] = {0};
        for( char ch: p){
            hash[ch - 'a']++;
        }
        int count = 0;
        while( right < s.size() ){
            if( hash[s[right] - 'a'] > 0 ){
                count++;
            }
            hash[s[right]-'a']--;
            if(  count == m || right - left + 1 == m){
                if( count == m){ // here in if condition we can either check using allZero function or just count
                   // cout<<" left: "<<left<<" right: "<<right<<" count: "<<count<<endl;
                    ans.push_back(left);
                }
                hash[s[left]-'a']++;
                if( hash[s[left] - 'a'] > 0){
                    count--;
                }
                left++;
                
            }
            right++;
        }
        return ans;
        
    }
    vector<int> findAnagrams(string s, string p) {
        return method(s,p);
    }
};
