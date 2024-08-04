class Solution {
public:
    void countArrangementHelper(int &ans, vector<int>&v,int &n,int currNum){
        // base case
        if(currNum==n+1){
            ans++;
            return;
        }
        // starting from index 1 and checking every possibility by putting each value on each index,
        for(int i=1;i<=n;i++){
            //checking if a value has already been placed and checking condition given in question
            if(v[i]==0 && (i%currNum==0 || currNum%i==0)){
                //if condidtions are satisfied, we put value
                v[i]=currNum;
                // re
                countArrangementHelper(ans,v,n,currNum+1);
                // backtracking
                v[i]=0;
            }
        }
    }
    int countArrangement(int n) {
        vector<int>v(n+1);
        int ans=0;
        countArrangementHelper(ans,v,n,1);
        return ans;
    }
};
