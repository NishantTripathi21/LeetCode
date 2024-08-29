class Solution {
public:
    class comp{
        public:
        bool operator()(int a,int b){
            return a > b;
        }
    };
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>pq;
        for(auto i:piles){
            pq.push(i);
        }
        while(k){
            k--;
            auto temp=pq.top();
            pq.pop();
            pq.push(temp-temp/2);
        }
        int sum=0;
        while(!pq.empty()){
            sum+=pq.top();
            pq.pop();
        }
        return sum;

    }
};
