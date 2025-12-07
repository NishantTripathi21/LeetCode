class Solution {
public:
    int br(int x) {
        int r = 0;
        while (x > 0) {
            r = (r << 1) | (x & 1);
            x >>= 1;
        }
        return r;
    }
    vector<int> sortByReflection(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [&](int a, int b) {
            int ra = br(a);
            int rb = br(b);
            if (ra == rb) return a < b; 
            return ra < rb;            
        });

        return nums;
    }
};
