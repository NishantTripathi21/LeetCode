class Solution {
public:
    long long halfToPalindrome(long left, bool even) {
        long long resultNum = left;
        if (!even) {
            left = left / 10;
        }

        while (left > 0) {
            int digit = left % 10;
            resultNum = (resultNum * 10) + digit;
            left /= 10;
        }
        return resultNum;
    }
    string nearestPalindromic(string n) {
        /* only few cases are possile 
          1. Palindrome by mirroring the first half.
          2. Palindrome by mirroring the first half + 1.
          3. Palindrome by mirroring the first half - 1.
          4. Edge cases by considering palindromes of the form 999...and 100...001 
        */
        int len = n.size();
        int mid = len / 2;
        long long firstHalf = stol(n.substr(0, len % 2 == 0 ? mid : mid + 1));
        vector<long long> possibleResults;
        possibleResults.push_back(halfToPalindrome(firstHalf, len % 2 == 0));
        possibleResults.push_back(halfToPalindrome(firstHalf + 1, len % 2 == 0));
        possibleResults.push_back(halfToPalindrome(firstHalf - 1, len % 2 == 0));
        possibleResults.push_back((long long)pow(10, len - 1) - 1);
        possibleResults.push_back((long long)pow(10, len) + 1);
        long long diff = LONG_MAX;
        long long result = 0;
        long long originalNum = stol(n);

        for (long long &num : possibleResults) {
            if (num == originalNum) continue;
            if (abs(num - originalNum) < diff) {
                diff = abs(num - originalNum);
                result = num;
            }
            else if (abs(num - originalNum) == diff) {
                result = min(result, num);
            }
        }
        return to_string(result);
    }
};
