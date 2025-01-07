class Solution {
public:
    int minMoves(vector<int>& nums) {
        // increasing all n-1 element except the largest one is similar to decreasing the largest element only 
        // So the smallest elements need not to decrease any more and rest of elements will got decremented 
        // upto smallest one. In this way the total number of operation required for making all elements 
        // equal will be 
        // arraySum – n * (smallestElement). 
        int sum = 0;
        int smallest = INT_MAX;
        for ( int i: nums){
            sum += i;
            smallest = min( i, smallest);
        }
        int size = nums.size();
        return sum - size*smallest;

    }
};
