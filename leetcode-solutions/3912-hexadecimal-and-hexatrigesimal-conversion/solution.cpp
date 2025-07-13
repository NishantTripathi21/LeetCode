class Solution {
public:
    string toBase36(long long num) {
        if (num == 0) return "0";
        string chars = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        string result;
        while (num > 0) {
            result += chars[num % 36];
            num /= 36;
        }
        reverse(result.begin(), result.end());
        return result;
    }

    string toHex(long long num) {
        if (num == 0) return "0";
        string chars = "0123456789ABCDEF";
        string result;
        while (num > 0) {
            result += chars[num % 16];
            num /= 16;
        }
        reverse(result.begin(), result.end());
        return result;
    }
    string concatHex36(int n) {
        long long square = 1LL * n * n;
        long long cube = 1LL * n * n * n;

        string hexPart = toHex(square);
        string base36Part = toBase36(cube);

        return hexPart + base36Part;
    }
};
