class Solution {
public:
    int method1( int n){
        string s = to_string(n);
        int size = s.size();
        
        //Find the first decreasing element from the right
        int i = size - 2;
        while (i >= 0 && s[i] >= s[i + 1]) {
            i--;
        }
        
        // If no such element is found, no larger permutation is possible
        if (i < 0) {
            return -1;
        }
        
        //Find the smallest element greater than s[i] to the right of i
        int j = size - 1;
        while (s[j] <= s[i]) {
            j--;
        }

        swap(s[i], s[j]);
        reverse(s.begin() + i + 1, s.end());
        long long result = stoll(s);
        return (result > INT_MAX) ? -1 : (result);
    }
    int nextGreaterElement(int n) {
        return method1(n);
    }
};
