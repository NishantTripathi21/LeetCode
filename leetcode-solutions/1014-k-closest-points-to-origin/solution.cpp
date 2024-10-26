class Solution {
public:
    class info{
        public:
        int dist;
        vector<int>coordinate;
        info(int a, vector<int>b){
            dist=a;
            coordinate=b;
        }
    };
    class comp{
        public:
            bool operator()(info a,info b){
                return a.dist < b.dist;
            }
    };
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<info,vector<info>,comp>q;
        for(int i=0;i<k;i++){
            auto temp= points[i];
            int dist=(points[i][0]*points[i][0] + points[i][1]*points[i][1] );
            info a(dist,temp);
            q.push(a);
        }
        int index=k;
        while(index < points.size()){
            info temp=q.top();
            auto curr=points[index];
            int distCurr= (curr[0]*curr[0] + curr[1]*curr[1]);
            int distTemp=temp.dist;
            cout<<"tempDist: "<<distTemp<<endl;
            if(distCurr < distTemp){
                q.pop();
                info i(distCurr,curr);
                q.push(i);
            }
            index++;
        }
        vector<vector<int>>ans;
        while(!q.empty()){
            ans.push_back(q.top().coordinate);
            q.pop();
        }
        return ans;

    }
};
