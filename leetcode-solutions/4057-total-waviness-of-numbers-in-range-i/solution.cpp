class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int t = 0;
        for (int x = num1; x <= num2; x++) {
            string s = to_string(x);
            int n = s.size();
            if (n < 3) continue; 
            for (int i = 1; i < n - 1; i++) {
                if (s[i] > s[i - 1] && s[i] > s[i + 1]) t++;     
                else if (s[i] < s[i - 1] && s[i] < s[i + 1]) t++;
            }
        }
        return t;
    }
};
