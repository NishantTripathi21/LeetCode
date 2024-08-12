class Solution {
    vector<int> findNextsmallest(vector<int> &arr) {
    vector<int>ans(arr.size());
    stack<int> st;
    st.push(-1);  // Initialize the stack with -1

    for(int i = arr.size()-1; i >= 0; i--) {
        int curr = arr[i];
        while( st.top()!=-1 && arr[st.top()] >= curr) {
            st.pop();
        }
       
        ans[i] = st.top();  // Store the next smallest element'index in ans
        
        st.push(i);
    }
    return ans;
}


vector<int> previousSmallerElement(vector<int> &arr) {
    vector<int>ans(arr.size());
    stack<int> st;
    st.push(-1);  // Initialize the stack with -1

    for(int i = 0; i <arr.size(); i++) {
        int curr = arr[i];
        while( st.top()!=-1 && arr[st.top()] >= curr) {
            st.pop();
        }
        ans[i] = st.top();  // Store the next smallest element in ans
        st.push(i);
    }
   return ans;
}
    int largestRectangleArea(vector<int>& heights) {
        vector<int>prev =previousSmallerElement(heights);
        //check iff any element is -1
        vector<int>next=findNextsmallest(heights);
        for(int i=0;i<next.size();i++){
            if(next[i]==-1){
                next[i]=heights.size();
            }
        }
        int area=INT_MIN;
        for(int i=0;i<heights.size();i++){
            int width=next[i]-prev[i]-1;
            area=max(width*heights[i],area);

        }
        return area;
      
    }
public: 
    int maximalRectangle(vector<vector<char>>& matrix) {
       vector<vector<int>>v;
       int n=matrix.size();
       int m=matrix[0].size();
       for(int i=0;i<n;i++){
        vector<int>temp;
        for(int j=0;j<m;j++){
            temp.push_back(matrix[i][j]-'0');
        }
        v.push_back(temp);
       }
       int area=largestRectangleArea(v[0]);
       for(int i=1;i<n;i++){
           for(int j=0;j<m;j++){
            if(v[i][j] && i){
                v[i][j]+=v[i-1][j];
            }
            else{
                v[i][j]=0;
            }
            
           }
           area=max(largestRectangleArea(v[i]),area);
       }
       return area;
    }
};
