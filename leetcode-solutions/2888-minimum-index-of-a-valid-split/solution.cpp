class Solution {
public:
    pair<int,int> majorityEle(vector<int>& nums) {
        int candidate = 0;
        int count = 0;
        int index = 0;
        int fre = 0;
        while( index < nums.size()){
            if(count == 0){
                candidate = nums[index];
                count++;
                index++;
            }
            else{
                if(nums[index] == candidate){
                    count++;
                }
                else{
                    count--;
                }
                index++;
            }
        }
        for(int i: nums) {
            if(i == candidate)fre++;
        }
        pair<int,int>p = {fre,candidate};
        return p;
    } 
    int minimumIndex(vector<int>& nums) {
        auto [fre,majority] = majorityEle(nums);
        int count = 0;
        //cout<<majority;
        int n = nums.size();
        for(int i= 0; i< n; i++) {
            if(nums[i] == majority) {
                count++;
            }
            int size1 = i + 1;
            int size2 = n - i - 1;
            if(count > size1/2 && (fre-count) > size2/2)return i;
        }
        return -1;
    }
};
