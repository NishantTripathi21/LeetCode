class Solution {
public:
    int method( string s){
        int hash[26] = {0};
        int minLen = 0;
        int index = 0;
        while( index < s.size()){
            hash[s[index]-'a']++;
            index++;
        }
        for( int i=0; i< 26;  i++){
            if(hash[i] != 0){
                int count = hash[i];
                if( count & 1){
                    minLen += 1;
                }
                else{
                    minLen += 2;
                }
            }
        }
        return minLen;

    }
    int minimumLength(string s) {
        return method(s);
    }
};
