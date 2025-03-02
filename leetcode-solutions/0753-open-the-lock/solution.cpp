class Solution {
public:
    int bfs(vector<string>& deadends, string target) {
        unordered_map<string,int>visited;
        queue<pair<string,int>>que; // string,transformations
        unordered_set<string>invalid(deadends.begin(),deadends.end());
        que.push({"0000",0});
        if(invalid.find("0000") != invalid.end())return -1;
        visited["0000"]= 1;
        while(!que.empty()) {
            auto [str,trx] = que.front();
            que.pop();
            visited[str] = 1;
            if(str == target)return trx;
            for(int i= 0; i< 4; i++) {
                char ori = str[i];
                for(int d:{-1,1}){
                    str[i] = (str[i] - '0' + d + 10) % 10 + '0';
                    if(visited.find(str) == visited.end() && invalid.find(str) == invalid.end()){
                        que.push({str,trx+1});
                        visited[str] = 1; 
                    }
                    str[i] = ori;
                }
            }
        }
        return -1;
    }
    int openLock(vector<string>& deadends, string target) {
        return bfs(deadends,target);
    }
};
