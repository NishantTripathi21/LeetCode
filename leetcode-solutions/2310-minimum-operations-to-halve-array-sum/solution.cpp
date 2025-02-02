class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double>maxHeap(nums.begin(),nums.end());
        
        double sum = accumulate(nums.begin(),nums.end(),0.0);
        double targetSum = (double)sum/2;
        int operations = 0;
        while( true ) {
            double top = maxHeap.top();
            maxHeap.pop();
            sum -= top;
            double newMember = (double)top / 2;
            operations++;
            sum += newMember;
            maxHeap.push(newMember);
            if( sum <= targetSum)break;
        }
        return operations;
    }
};
