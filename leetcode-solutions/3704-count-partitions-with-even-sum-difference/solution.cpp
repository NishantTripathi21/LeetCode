class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int sum = 0;
        for( int i: nums){
            sum += i;
        }
        int count = 0;
        int left = 0;
        for( int i = 0; i< nums.size()-1; i++){
            left += nums[i];
            int right = sum - left;
            if( abs(right-left) % 2 == 0)count++;
            //cout<<" left: "<<left<<" right: "<<right<<endl;
        }
        return count;
    }
};
