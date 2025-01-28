class Solution {
public:
    vector<int> findNextSmaller(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse(n, -1); 
        stack<int> s; 

        for (int i = n-1; i >= 0; i--) {
            while (!s.empty() && arr[s.top()] >= arr[i]) {
                s.pop();
            }
            if(!s.empty()){
                nse[i] = s.top();   
            }
            s.push(i);
        }

        return nse;
    }

    vector<int> findPreviousGreater(const vector<int>& arr) {
        int n = arr.size();
        vector<int> pge(n, -1); 
        stack<int> s; 

        for (int i = 0; i < n; i++) {
            while (!s.empty() && arr[s.top()] < arr[i]) {
                s.pop();
            }

            if (!s.empty()) {
                pge[i] = s.top();
            }
            s.push(i);
        }
        return pge;
    }

    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        
        int left = -1, right = -1;
        int maxElement = INT_MIN, minElement = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (nums[i] < maxElement) {
                right = i;
            }
            else {
                maxElement = max(maxElement, nums[i]);
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] > minElement) {
                left = i;
            }
            else {
                minElement = min(minElement, nums[i]);
            }
        }
        return (left == -1) ? 0 : (right - left + 1);
    }
};
