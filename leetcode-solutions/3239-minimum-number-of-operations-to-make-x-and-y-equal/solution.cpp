class Solution {
public:
    int bfs(int x, int y) {
        unordered_set<int>vis;
        vis.insert(x);
        queue<int>q;
        q.push(x);
        int steps = 0;
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                int number = q.front();
                q.pop();
                if(number == y)return steps;
                int nn;
                //op1 - x/11
                nn = number/11;
                //cout<<" nn: "<<nn<<endl;
                if( number % 11 == 0 && vis.find(nn) == vis.end()) {
                    q.push(nn);
                    vis.insert(nn); 
                }
                //op2 - x/5
                nn = number/5;
                if(number % 5 == 0 && vis.find(nn) == vis.end()) {
                    q.push(nn);
                    vis.insert(nn);
                }

                nn = number - 1;
                if(vis.find(nn) == vis.end()) {
                    q.push(nn);
                    vis.insert(nn);
                }
                nn = number + 1;
                if(vis.find(nn) == vis.end()) {
                    q.push(nn);
                    vis.insert(nn);
                }
            }
            steps++;
        }
        return steps;
    }
    int minimumOperationsToMakeEqual(int x, int y) {
        return bfs(x,y);
    }
};
