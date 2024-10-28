class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
       priority_queue<int>pq;
       int max_car_can_go=startFuel;
       int ans=0;
       int index=0;                       
       while(max_car_can_go < target){
            while(index < stations.size() && stations[index][0] <= max_car_can_go){
                pq.push(stations[index][1]);
                index++;
            }
            if(pq.empty())return -1;
            ans++;
            max_car_can_go+=pq.top();
            pq.pop();
        }
        cout<<max_car_can_go;
        return ans; 
    }
};
