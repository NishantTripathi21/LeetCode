class Solution {
public:
    bool scoreBalance(string s) {
        int tscore =  0;
        for(char ch: s) {
            tscore += ch-'a'+1;
        }
        if(tscore & 1)return false;
        tscore = tscore / 2;
        int score = 0;
        for(char ch: s) {
            score += ch-'a'+1;
            if(score == tscore)return true;
        }
        return false;

    }
};
