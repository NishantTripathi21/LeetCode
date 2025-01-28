class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        deque<int>maxiWindow,miniWindow; 
        int left = 0;
        int right = 0;
        long long subarrays = 0;
        while( right < nums.size()) {
            int element = nums[right];
            while(!maxiWindow.empty() && nums[maxiWindow.back()] <= element) {
                maxiWindow.pop_back();
            }
            while(!miniWindow.empty() && nums[miniWindow.back()] >=element) {
                miniWindow.pop_back();
            }
            maxiWindow.push_back(right);
            miniWindow.push_back(right);
            int mini = nums[miniWindow.front()];
            int maxi = nums[maxiWindow.front()];
            if( abs(mini-maxi) > 2) {
                left++;
                if( !maxiWindow.empty() && maxiWindow.front() < left){
                    maxiWindow.pop_front();
                }
                if( !miniWindow.empty() && miniWindow.front() < left){
                    miniWindow.pop_front();
                }
            }
            else{
                subarrays += (long long) right-left+1;
                right++;
            }
            //cout<<" left: "<<left<<" right: "<<right<<" mini: "<<mini<<" maxi: "<<maxi<<" subarrays: "<<subarrays<<endl;
        }
        return subarrays;
    }
};
