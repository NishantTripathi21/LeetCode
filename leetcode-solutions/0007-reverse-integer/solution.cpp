class Solution {
public:
 int reverse(int x) {
    int reversedNumber = 0;
    
    while (x != 0) {
        int lastDigit = x % 10;
        x /= 10;

        // Check for overflow/underflow before multiplying and adding the digit
        if (reversedNumber > INT_MAX / 10 || (reversedNumber == INT_MAX / 10 && lastDigit > 7)) {
            return 0; // Overflow
        }
        if (reversedNumber < INT_MIN / 10 || (reversedNumber == INT_MIN / 10 && lastDigit < -8)) {
            return 0; // Underflow
        }

        reversedNumber = reversedNumber * 10 + lastDigit;
    }
    
    return reversedNumber;
}
};
