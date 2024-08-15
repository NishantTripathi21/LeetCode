class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> ans;
    deque<int> dq;
    int size = nums.size();
    // first window process till k size
    for (int i = 0; i < k; i++)
    {
        int ele = nums[i];
        // push elements in the queue and remove chote vale elements
        while (!dq.empty() && ele > nums[dq.back()])
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }

    // processs the remaining window Removal and Insertion
    for (int i = k; i < size; i++)
    {

        ans.push_back(nums[dq.front()]);

        // remove
        if (i - dq.front() >= k)
            dq.pop_front();
        int ele = nums[i];
        // push elements in the queue and remove chote vale elements
        while (!dq.empty() && ele > nums[dq.back()])
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    // handle last window
    ans.push_back(nums[dq.front()]);

    return ans;
    }
};
