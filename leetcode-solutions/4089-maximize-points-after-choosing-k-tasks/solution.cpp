class Solution {
public:
    long long maxPoints(vector<int>& technique1, vector<int>& technique2, int k) {
        long long total = 0;
        priority_queue<long long> pq;
        for(int i = 0; i < technique1.size(); ++i) {
            total += technique2[i];
            pq.push((long long)technique1[i] - technique2[i]);
        }
        while(k--) {
            total += pq.top(); 
            pq.pop();
        }
        while(!pq.empty() && pq.top() > 0) {
            total += pq.top();
            pq.pop();
        }
        return total;
    }
};
