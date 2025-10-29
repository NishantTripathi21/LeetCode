class Solution {
public:
    int bfs(int x, int y) {
        unordered_map<int,int>mp;
        mp[x]++;
        queue<int>q;
        q.push(x);
        int count = 0;
        while(!q.empty()) {
            int size = q.size();
            for(int i= 0; i< size; i++) {
                int t = q.front();
                q.pop();
                if(t == y)return count;
                if( t % 11 == 0 && !mp.count(t/11)) {
                    q.push(t/11);
                    mp[t/11]++;
                }
                if( t % 5 == 0 && !mp.count(t/5)) {
                    q.push(t/5);
                    mp[t/5]++;
                }
                if(!mp.count(t-1)) {
                    q.push(t-1);
                    mp[t-1]++;
                }
                if( !mp.count(t+1)) {
                    q.push(t+1);
                    mp[t+1]++;
                }
            }
            count++;
        }
        return -1;
    }
    int minimumOperationsToMakeEqual(int x, int y) {
        return bfs(x,y);
    }
};
