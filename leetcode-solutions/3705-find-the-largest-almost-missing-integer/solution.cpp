class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freq;
        for(int i= 0; i<= n -k; i++) {
            set<int>vis;
            for(int j= i; j< i+k; j++) {
                vis.insert(nums[j]);
            }
            for(int num: vis){
                freq[num]++;
            }
        }
        int result  = -1;
        for(auto [num,fre]:freq) {
            if(fre==1){
                result = max(result,num);
            }
        }
        return result;
    }
};
