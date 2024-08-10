class MinStack {
public:
    vector<pair<int,int>>st;

    MinStack() {
         
        
    }
    
    void push(int val) {
        if(st.empty()){
            pair<int,int>temp;
            temp.first=val;
            temp.second=val;
            st.push_back(temp);
        }
        else{
            pair<int,int>temp;
            temp.first=val;
            temp.second=min(st.back().second,val);
            st.push_back(temp);
        }
        
    }
    
    void pop() {
        st.pop_back();
    }
    
    int top() {
        return st.back().first;
        
    }
    
    int getMin() {
        return st.back().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
