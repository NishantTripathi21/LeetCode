class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> height(n,0);
        int totalSub = 0;
        for( int i= 0; i< m; i++) {
            // update height
            for( int j = 0; j< n; j++) {
                height[j] = (mat[i][j]==0)? 0: height[j]+1;
            }
            // use stack to calculate prev Smaller height index
            stack<int>st;
            vector<int>count(n,0); // to store sabMatrix count
            for( int j = 0; j< n; j++) {
                while( !st.empty() && height[st.top()] >= height[j]) {
                    st.pop();
                }
                if( st.empty()){
                    count[j] = height[j] * (j+1);
                }
                else{
                    int prevIndex = st.top();
                    count[j] = height[j]* ( j-prevIndex)+count[prevIndex];
                }
                st.push(j);
                totalSub += count[j];
            }

        }
        return totalSub;
    }
};
