class Solution {
public:
    // string solve1(string s) {
    //     string ans = s;
    //     for(int left = 0; left < s.size();){
    //         int right = left;
    //         string temp = s;
    //         while(right < s.size() && s[right] != 'a'){
                    
    //         }
    //     }
    // }
    string solve2(string s) {
        int n = s.size();
        int index  = 0;
        int startIndex = -1;
        int endIndex = -1;
        while(index < s.size()) {
            int val = s[index]-'a';
            if(val != 0) {
                startIndex = index;
                while(val != 0 && index < n) {
                    endIndex = index;
                    val = s[++index]-'a';
                }
            }
            else index++;
            if(startIndex != -1)break;
        }
        if(startIndex == -1) {
            s[n-1] = 'z';
            return s;
        }
        else {
            for(int i= startIndex; i<= endIndex; i++) {
                int ch = s[i]-'a';
                s[i] = ch-1 + 'a';
            }
            return s;
        }

    }
    string smallestString(string s) {
        return solve2(s);
    }
};
