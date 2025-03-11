class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int,double>>>adj(n);
        int i = 0;
        for(auto it: edges) {
            int u = it[0];
            int v = it[1];
            double wt = succProb[i];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
            i++;
        }

        priority_queue<pair<double,int>>maxHeap; //{probability,node}

        vector<double>track(n,0.00000);
        maxHeap.push({1.0000,start_node});
        track[start_node] = 1.000;
        while(!maxHeap.empty()) {
            auto [pro,node] = maxHeap.top();
            maxHeap.pop();
            //cout<<" proba: "<<pro<<" node: "<<node<<endl;
            if(node == end_node)return pro;
            for(auto [nbr,wt]: adj[node]) {
                double newPro = double(wt * pro);
                //cout<<" proba: "<<pro<<" node: "<<node<<" newPro: "<<newPro<<" nbr: "<<nbr<<endl;
                if(track[nbr] < newPro) {
                    track[nbr] = newPro;
                    maxHeap.push({newPro,nbr});
                }
            }
        }
        return 0;
    }
};
