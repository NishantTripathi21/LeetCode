class Solution {
public:
    int bfs(vector<int>& nums, int start, int goal) {
        unordered_set<int>st;
        int steps = -1;
        queue<int>q;
        q.push(start);
        st.insert(start);
        while(!q.empty()) {
            steps++;
            int size = q.size();
            while(size--) {
                int number = q.front();
                q.pop();
                if(number == goal)return steps;
                //if(number < 0 || number > 1000) continue;
                for(int i= 0; i< nums.size(); i++) {
                    int newNumber;
                    // op1: Addition
                    newNumber = number + nums[i];
                    if(newNumber == goal)return steps+1;
                    if ((newNumber >=0 && newNumber <= 1000) && st.find(newNumber) == st.end()) {
                        st.insert(newNumber);
                        q.push(newNumber);
                    }

                    // op2: Subtraction
                    newNumber = number - nums[i];
                    if(newNumber == goal)return steps+1;
                    if ((newNumber >=0 && newNumber <= 1000) && st.find(newNumber) == st.end()) {
                        st.insert(newNumber);
                        q.push(newNumber);
                    }

                    // op3: XOR
                    newNumber = number ^ nums[i];
                    if(newNumber == goal)return steps+1;
                    if ((newNumber >=0 && newNumber <= 1000) && st.find(newNumber) == st.end()) {
                        st.insert(newNumber);
                        q.push(newNumber);
                    }
                }
            }
        }
        return -1;
    }
    int minimumOperations(vector<int>& nums, int start, int goal) {
        return bfs(nums,start,goal);
    }
};
