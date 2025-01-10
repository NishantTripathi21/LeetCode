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
    bool method( string s, string p){
        int right = 0;
        int left = 0;
        int m = p.size();
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
            if(  count == m || right - left + 1 >= m){
                if( allzero(hash)){
                   // cout<<" left: "<<left<<" right: "<<right<<" count: "<<count<<endl;
                    return true;
                }
                hash[s[left]-'a']++;
                if( hash[s[left] - 'a'] > 0){
                    count--;
                }
                left++;
                
            }
            right++;
        }
        return false;
        
    }
    bool checkInclusion(string s1, string s2) {
        return method(s2,s1);
    }
};
