class Solution {
public:
    class Info{
        public:
        int data;
        int colIndex;
        int rowIndex;
        Info(int a, int b,int c){
            this->data=a;
            this->colIndex=c;
            this->rowIndex=b;
        }
    };
    class comp{
        public:
        bool operator()(Info&a,Info&b){
            return a.data > b.data;
        }
    };
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<Info,vector<Info>,comp>pq;
        int maxi=INT_MIN;
        int mini=INT_MAX;
        for(int i=0;i<nums.size();i++){
            int element=nums[i][0];
            Info newInfo(element,i,0);
            pq.push(newInfo);
            maxi=max(maxi,element);
            mini=min(mini,element);
        }
        int ansmax=maxi;
        int ansmin=mini;
        while(!pq.empty()){
            auto temp=pq.top();
            pq.pop();
            int topData=temp.data;
            int topRow=temp.rowIndex;
            int topCol=temp.colIndex;
            mini=topData;
            if((maxi-mini ) < (ansmax - ansmin )){
                ansmax=maxi;
                ansmin=mini;
            }
            //insertion 
            if(topCol+1 < nums[topRow].size()){
                int element=nums[topRow][topCol+1];
                maxi=max(maxi,element);
                Info newInfo(element,topRow,topCol+1);
                pq.push(newInfo);
            }
            else{
                break;
            }
        }
        vector<int>ans;
        ans.push_back(ansmin);
        ans.push_back(ansmax);
        return ans;
    }
};
