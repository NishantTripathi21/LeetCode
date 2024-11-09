class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> ans;
    deque<int> dq;
    int size = nums.size();
    // first window process till k size
    for(int i = 0; i < k; i++){
        int element=nums[i];
        while(!dq.empty() && nums[dq.back()] < element){
            dq.pop_back();
        }
        dq.push_back(i);
    }
    for(int i=k ; i< nums.size(); i++){
        int element=nums[i];
        ans.push_back(nums[dq.front()]);
        if( i - dq.front() >= k){
            dq.pop_front();
        }
        while(!dq.empty() && nums[dq.back()] < element){
            dq.pop_back();
        }
        dq.push_back(i);
    }
    //last window
    ans.push_back(nums[dq.front()]);
    return ans;
    }
};
