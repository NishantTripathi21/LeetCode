class Solution {
public:
    vector<int> implement(vector<int>& nums, int k, int x){
        vector<int> countNeg(51, 0); // Frequency array for negative numbers (-50 to -1)
        int left = 0;
        vector<int> ans;
        
        // Initialize the frequency array for the first k elements
        for (int right = 0; right < k; ++right) {
            if (nums[right] < 0) {
                countNeg[nums[right] + 50]++;
            }
        }

        for (int right = k; right <= nums.size(); ++right) {
            // Find the xth smallest negative integer
            int negCount = 0;
            int beauty = 0;
            for (int i = 0; i <= 50; ++i) {
                negCount += countNeg[i];
                if (negCount >= x) {
                    beauty = i - 50;
                    break;
                }
            }

            // If there are fewer than x negative numbers, beauty should be 0
            if (negCount < x) {
                beauty = 0;
            }

            ans.push_back(beauty);

            // Slide the window: remove the element going out of the window and add the new element
            if (right < nums.size()) {
                if (nums[left] < 0) {
                    countNeg[nums[left] + 50]--;
                }
                if (nums[right] < 0) {
                    countNeg[nums[right] + 50]++;
                }
            }

            left++;
        }

        return ans;

    }
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        return implement( nums, k ,x);
    }
};
