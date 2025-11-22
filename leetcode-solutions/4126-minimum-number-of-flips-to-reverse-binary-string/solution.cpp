class Solution {
public:
    int minimumFlips(int n) {
        string s = bitset<64>(n).to_string();
        s = s.substr(s.find('1'));
        string r = s;
        reverse(r.begin(), r.end());
        int f = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != r[i]) f++;
        }
        return f;
    }
};
