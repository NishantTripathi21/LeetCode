class Solution {
public:
    int method( string s){
        unordered_map<char, int> charIndexMap;
        int maxLength = 0;
        int left = 0;
        for( int i= 0; i< s.size(); i++){
            if( charIndexMap.find( s[i]) != charIndexMap.end() && charIndexMap[s[i]] >= left ){
                left = charIndexMap[s[i]]+1;
            }
            charIndexMap[s[i]] = i;
            maxLength = max( maxLength, i - left + 1);
        }
        return maxLength;
    }
    int lengthOfLongestSubstring(string s) {
        // unordered_map<char, int> charIndexMap;
        // int maxLength = 0;
        // int left = 0;

        // for (int right = 0; right < s.length(); ++right){
        //     if(charIndexMap.find(s[right]) != charIndexMap.end() && charIndexMap[s[right]] >= left) {
        //         left = charIndexMap[s[right]] + 1;
        //     }
        //     charIndexMap[s[right]] = right;
        //     maxLength = max(maxLength, right - left + 1);
        // }

    return method(s);
    }
};
