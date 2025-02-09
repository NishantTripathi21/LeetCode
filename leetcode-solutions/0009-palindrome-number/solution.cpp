class Solution {
public:
    bool isPalindrome(int x) {
            if (x < 0) return false;
            double original = x, reversed = 0;
            // Reverse the number
            while (x != 0) {
                int digit = x % 10;
                reversed = reversed * 10 + digit;
                x /= 10;
            }
        return original == reversed;
    }
};
