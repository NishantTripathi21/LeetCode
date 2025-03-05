class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<int>vis(n,0);
        queue<int>q; // index is pushed
        q.push(start);
        vis[start] = 1;
        while(!q.empty()) {
            int index = q.front();
            q.pop();
            if(arr[index] == 0)return true;

            if(index - arr[index] >= 0 && vis[index-arr[index]] == 0){
                q.push(index-arr[index]);
                vis[index-arr[index]] = 1;
            }

            if(index + arr[index] < n && vis[index+arr[index]] == 0) {
                q.push(index+arr[index]);
                vis[index+arr[index]] = 1;
            }
        }
        return false;
    }
};
