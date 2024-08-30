class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        //initiate max heap so that we can operate on maximum element.
        //operation on maximum elelemt will give us minimum result
        priority_queue<int>pq;
        for(auto i:piles){
            //push elements in max heap/
            pq.push(i);
        }
        while(k){
            //operate k number of times
            k--;
            auto temp=pq.top();
            pq.pop();
            pq.push(temp-temp/2);
        }
        int sum=0;
        //sum each element
        while(!pq.empty()){
            sum+=pq.top();
            pq.pop();
        }
        return sum;

    }
};
