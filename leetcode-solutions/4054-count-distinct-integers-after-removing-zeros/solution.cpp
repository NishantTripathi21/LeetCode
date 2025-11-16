class Solution {
public:
    long long countDistinct(long long n) {
        string s = to_string(n);
        int size = s.size();
        long long count = 0;
        long long p = 9;

        for(int i = 1; i < size; i++) {
            count +=  pow(9,i);
        }
        for(int i = 0; i < size; i++) {
            int digit = s[i] - '0';
            if (digit == 0) break;
            int choices = (digit - 1);
            if (choices > 0) {                
                count += choices * pow(9,size-i-1);
            }
        }
        bool isCount = true;
        for(char c : s) {
            if (c == '0') { 
                isCount = false;
                break; 
            }
        }
        if (isCount) count++;
        return count;
    }
};
