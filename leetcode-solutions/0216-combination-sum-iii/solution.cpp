class Solution {
public:
    void usingRec(int num, int k , int n, vector<vector<int>>&ans,vector<int>temp){
        if(k < 0)return ;
        if(num > 10)return;
        cout<<" K: "<<k<<" n: "<<n<<" num: "<<num<<endl;
        if(k==0 && n==0){
            ans.push_back(temp);
            return;
        }

        //exclude
        usingRec(num+1, k, n ,ans,temp);
        //include
        temp.push_back(num);
        usingRec(num+1, k-1, n - num, ans,temp);
        
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>temp;
        usingRec(1,k,n,ans,temp);
        return ans;
    }
};
