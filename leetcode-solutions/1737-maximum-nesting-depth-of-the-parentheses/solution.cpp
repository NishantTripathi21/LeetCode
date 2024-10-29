class Solution {
public:
    int maxDepth(string s) {
        int ans=0;
        int maxDepth=ans;
        for(auto i:s){
            if(i=='('){
                ans+=1;
                maxDepth=max(ans,maxDepth);
            }
            else if(i==')'){
                ans=ans-1;
            }
            else{
                continue;
            }
        }
        return maxDepth;
    }
};
