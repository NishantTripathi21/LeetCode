class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        multiset<int>track;
        int left = 0;
        int right = 0;
        long long count = 0;
        while( right < nums.size()) {
            int val = nums[right];
            track.insert(val);
            while( abs((*track.begin())- (*track.rbegin())) > 2 ) {
                int tr = nums[left];
                auto ptr = track.find(tr);
                track.erase(ptr);
                left++;
            }
            count += (long long)(right-left) + 1;
            right++;
        }
        return count;
    }
};
