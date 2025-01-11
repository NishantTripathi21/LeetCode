class Solution {
public:
    int method(string s, int maxLetters, int minSize, int maxSize){
        int maxi = 0;
        unordered_map<string,int>freq;
        for( int size= minSize; size<= maxSize ; size++){
            int left = 0;
            int right = 0;
            int count = 0;
            int hash[26] = {0};
            while( right < s.size()){
                if( hash[s[right]-'a'] > 0){
                    count++;
                }
                hash[s[right]-'a']++;
                if( right - left +1 == size) {
                    if( right - left +1 - count <= maxLetters){
                        //cout<<" right: "<<right<<" left: "<<left<<" count: "<<count<<endl;
                        string str = s.substr(left,size);
                        freq[str]++;
                        maxi = max( freq[str],maxi);
                    }
                    hash[s[left]-'a']--;
                    if( hash[s[left]-'a'] > 0){
                        count--;
                    }
                    left++;
                }
                right++;
            }
        }
            
        return maxi;
    }
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        return method(s,maxLetters,minSize,maxSize);
    }
};
