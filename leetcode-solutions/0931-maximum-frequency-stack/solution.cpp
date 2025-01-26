class FreqStack {
public:
    int maxFreq; // stores maxFrequency
    unordered_map<int,int>freq; // frequency of each elements
    unordered_map<int,stack<int>>grp; // frequency -> values having same frequency
    FreqStack() {
        
    }
    
    void push(int val) {
        freq[val]++;
        int currFreq = freq[val];
        maxFreq = max( maxFreq , currFreq);
        grp[currFreq].push(val);
    }
    
    int pop() {
        int ele = grp[maxFreq].top();
        grp[maxFreq].pop();
        freq[ele]--;
        if( grp[maxFreq].empty()){
            grp.erase(maxFreq);
            maxFreq--;
        }
        return ele;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
