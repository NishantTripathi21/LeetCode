class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        set<int> result_set;
        for(int j = 0; j < nums.size(); ++j){
            if(nums[j] == key){
                for(int i = max(0, j - k); i <= min(int(nums.size()) - 1, j + k); ++i){
                    result_set.insert(i);
                }
            }
        }
        return vector<int>(result_set.begin(), result_set.end());
    }
};
