class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int i : nums)freq[i]++;
        int sum = 0;
        for(auto [i, c] : freq) {
            if (c % k == 0)
                sum += i * c;
        }
    
        return sum;
    }
};
