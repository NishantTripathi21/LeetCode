class Solution {
public:
    
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int>track(n+1,0);
        for(int i= 0; i< shifts.size(); i++) {
            auto it = shifts[i];
            int st = it[0];
            int ed = it[1];
            int dir = it[2];
            if(dir) {
                track[st] += 1;
                track[ed + 1] += -1;
            }
            else {
                track[st] += -1;
                track[ed+1] += 1;
            }
        }
        int sum = 0;
        int index=  0;
        while(index < n) {
            sum += track[index];
            int val = s[index] - 'a';
            val = (val + (sum % 26) + 26) % 26;
            s[index] = val + 'a';
            index++;
        }
        return s;
    }
};
