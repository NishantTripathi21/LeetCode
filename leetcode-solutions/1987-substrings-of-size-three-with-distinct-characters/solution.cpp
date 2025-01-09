class Solution {
public:
    int countGoodSubstrings(string s) {
        if( s.size() < 3)return 0;
        unordered_map<char,int>mp;
        int left = 0;
        int ans = 0;
        int right = 0;
        for( right = 0; right <= 2;right++){
            mp[s[right]]++;
        }
        int count = 0;
            for( auto i:mp){
                if( i.second > 1)count++;
            }
            if( count == 0){
                ans += 1;
            }
        while( right < s.size()){
            char ch1 = s[right];
            char ch2 = s[left];
            mp[ch2]--;
            if( mp[ch2] == 0)mp.erase(ch2);
            mp[ch1]++;
            
            
            int count = 0;
            for( auto i:mp){
                if( i.second > 1)count++;
            }
            if( count == 0){
                ans += 1;
            }
            right++;
            left++;
        }   
        return ans;
    }
};
