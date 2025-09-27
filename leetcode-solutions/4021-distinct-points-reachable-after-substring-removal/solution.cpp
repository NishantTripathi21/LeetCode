class Solution {
public:
    int distinctPoints(string s, int k) {
        int x = 0;
        int y = 0;
        for(char ch: s) {
            if(ch == 'U') {
                y++;
            }
            else if(ch == 'D') {
                y--;
            }
            else if(ch == 'L') {
                x--;
            }
            else {
                x++;
            }
        }
        int left= 0;
        int right = 0;
        set<pair<int,int>>st;
        int tx = 0;
        int ty = 0;
        while(right < s.size()) {
            char ch = s[right];
            if(ch == 'U') {
                ty++;
            }
            else if(ch == 'D') {
                ty--;
            }
            else if(ch == 'L') {
                tx--;
            }
            else {
                tx++;
            }
            if(right-left+1 == k) {
                st.insert({x-tx,y-ty});
                char tch = s[left];
                if(tch == 'U') {
                    ty--;
                }
                else if(tch == 'D') {
                    ty++;
                }
                else if(tch == 'L') {
                    tx++;
                }
                else {
                    tx--;
                }
                left++;
            }
            right++;
        }
        return st.size();
    }
};
