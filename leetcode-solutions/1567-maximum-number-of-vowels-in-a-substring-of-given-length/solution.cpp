class Solution {
public:
    int implement( string s, int k){
        int left = 0;
        int right = 0;
        int vowelCount = 0;
        int count= 0;
        while( right < s.size()){
            if( s[right] == 'a' || s[right] =='e' || s[right] == 'i' || s[right] == 'o' || s[right]=='u'){
                count++;
            }
            if( (right - left +1) >= k){
                vowelCount = max(vowelCount , count);
                if(s[left] == 'a' || s[left] =='e' || s[left] == 'i' || s[left] == 'o' || s[left]=='u'){
                    count--;
                }
                left++;
            }
            right++;
        }
        return vowelCount;
    }
    int maxVowels(string s, int k) {
        return implement(s,k);
    }
};
