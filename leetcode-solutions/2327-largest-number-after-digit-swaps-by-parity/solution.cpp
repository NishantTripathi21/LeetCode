class Solution {
public:
    int largestInteger(int num) {
        string numStr = to_string(num);
        priority_queue<int> oddHeap, evenHeap;

        for (char c : numStr){
            int digit = c - '0';
            if (digit % 2 == 0) evenHeap.push(digit);
            else oddHeap.push(digit);
        }

        for (char& c : numStr){
            int digit = c - '0';
            if (digit % 2 == 0){  
                c = '0' + evenHeap.top();
                evenHeap.pop();
            } 
            else{
                c = '0' + oddHeap.top();
                oddHeap.pop();
            }
        }

        return stoi(numStr);
    }
};
