class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();
        priority_queue<int,vector<int>,greater<int>> minHeap1,minHeap2;
        long long ans = 0;
        
        int hired = 0;
        int left = 0;
        int right = n-1;
        
        while(hired < k){
            while( minHeap1.size() < candidates && left<=right ) {
                minHeap1.push(costs[left++]);
            }
            while( minHeap2.size() < candidates && right>=left) {
                minHeap2.push(costs[right--]);
            }         
            int a = minHeap1.size() > 0 ? minHeap1.top() : INT_MAX;
            int b = minHeap2.size() > 0 ? minHeap2.top() : INT_MAX;
            
            if(a <= b){
                ans += a;
                minHeap1.pop();
            }
            else{
                ans += b;
                minHeap2.pop();
            }
            hired++;
        }
        return ans;
    }
};
