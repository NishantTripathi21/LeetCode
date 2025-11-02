class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        priority_queue<int>pq;
        for(int i: nums) {
            pq.push(abs(i));
        }
        long long ans =1;
        int i = 0;
        while(i< 2) {
            int n = pq.top();
            pq.pop();
            ans *= n;
            i++;
        }
        return abs(ans * 100000);
    }
};
