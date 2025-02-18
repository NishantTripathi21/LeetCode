class Solution {
public:
    string smallestNumber(string pattern) {
        int n = pattern.size();
        string num = "123456789";
        int used = 0;
        string ans = "";
        for( int i = 0; i< pattern.size(); i++) {
            if( pattern[i] == 'I') {
                while( pattern[i] == 'I'){
                    i++;
                }
                while( used < i){
                    ans += num[used++];
                }
            }
            int dCount = 0;
            while( i < n && pattern[i] == 'D') {
                dCount++;
                i++;
            }
            dCount++;
            if(dCount) {
                string temp = num.substr(used,dCount);
                reverse(temp.begin(),temp.end());
                ans += temp;
                used += dCount;
            }

        } 
        if( ans.size() == n+1)return ans;
        return ans += num[used];
    }
};
