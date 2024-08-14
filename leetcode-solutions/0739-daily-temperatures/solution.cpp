class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int>st;
        vector<int>answer(temperatures.size(),0);
        st.push(-1);
        for(int i=temperatures.size()-1;i>=0;i--){
            int curr=temperatures[i];
            while(st.top()!=-1 && temperatures[st.top()]<=curr){
                st.pop();

            }
            if(st.top()==-1){
                answer[i]=0;
            }
            else{
                answer[i]=st.top()-i;
            }
            st.push(i);
            
            
        }
        return answer;
    }
};
