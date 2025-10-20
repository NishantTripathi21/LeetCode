class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int sum = 0;
        for(auto it: operations) {
            if(it == "++X" || it == "X++") {
                sum++;
            }
            else sum--;
        }
        return sum;
    }
};
