class Solution {
public:
    int operationCount( vector<int>& nums, int penality) {
        int operations = 0;
        for( int i: nums) {
            operations += ceil((double) i/(double)penality) - 1;
        }
        return operations;
    }
    int method( vector<int>& nums, int op) {
        int ans = 0;
        int low = 1;
        int high = *max_element(nums.begin(),nums.end());
        while( low <= high) {
            int mid = (low+high)/2; //penality
            // For a given penalty P, calculate the number of operations required to ensure that no bag has more than \U0001d443
            // balls.
            int requiredOperations = operationCount( nums, mid); // required operations to 
            if( requiredOperations <= op){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }

        }
        return ans;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        return method(nums,maxOperations);
    }
};
