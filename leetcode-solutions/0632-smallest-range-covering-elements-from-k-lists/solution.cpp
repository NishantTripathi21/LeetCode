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
        // we use min heap and max heap for this question, instead of max heap, we use max keyword
        //eloborated explanation is written in notebook
        priority_queue<Info,vector<Info>,comp>pq;
        int maxi=INT_MIN;
        int mini=INT_MAX;
        for(int i=0;i<nums.size();i++){
            //process first element of every array
            int element=nums[i][0];
            Info newInfo(element,i,0);
            pq.push(newInfo);
            maxi=max(maxi,element);
            mini=min(mini,element);
        }
        //initialise ans
        int ansStart=mini;
        int ansEnd=maxi;
        while(!pq.empty()){
            auto temp=pq.top();
            pq.pop();
            int topData=temp.data;
            int topRow=temp.rowIndex;
            int topCol=temp.colIndex;
            mini=topData;
            if((maxi-mini ) < (ansEnd - ansStart )){
                ansEnd=maxi;
                ansStart=mini;
            }
            //insertion 
            if(topCol+1 < nums[topRow].size()){
                //insert only when each of array is isnt iterated
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
        ans.push_back(ansStart);
        ans.push_back(ansEnd);
        return ans;
    }
};
