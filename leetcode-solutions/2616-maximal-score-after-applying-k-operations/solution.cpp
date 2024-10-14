class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<long long> pq;
        for(int num:nums){
            pq.push(num);
        }   
        long long score = 0;
        for(int i = 0;i<k;i++){
            int maxVal= pq.top();
            pq.pop();
            score += maxVal;
            //ceil(float number)
            pq.push((long long)ceil(maxVal / 3.0));
        }
        return score;
    }
};
