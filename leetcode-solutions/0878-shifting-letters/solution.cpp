class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        long long sum = accumulate(shifts.begin(),shifts.end(),1LL*0);
        for (int i= 0;  i< s.size(); i++) {
            int val = s[i]-'a';
            val = (val + sum) % 26;
            s[i] = val + 'a';
            sum -= shifts[i];
        }
        return s;
    }
};
