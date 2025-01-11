class Solution {
public:
    bool canConstruct(string s, int k) {
        int n = s.size();
        if( n < k)return false;
        int hash[26]= {0};
        for( char ch: s){
            hash[ch - 'a']++;
        }
        int oddCount = 0;
        for( int i= 0; i< 26; i++){
            if( hash[i] % 2 != 0){
                oddCount++;
            }
        }
        return oddCount <= k;
    }
};
