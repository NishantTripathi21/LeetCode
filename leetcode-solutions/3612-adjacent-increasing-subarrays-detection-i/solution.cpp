class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        if(k == 1) return true;
        for (int i = 0; i < nums.size(); i++) {
            int arrayCount = 0;
            int count = 1;

            for (int j = i; j < nums.size() - 1; j++) {
                if (nums[j] < nums[j + 1]) {
                    count++;

                    if (count == k) {
                        arrayCount++;
                        j++;       
                        count = 1; 
                    }
                } else {
                    break;
                }

                if (arrayCount == 2) {
                    break;
                }
            }

            if (arrayCount == 2) {
                return true;
            }
        }

        return false;
    }
};

