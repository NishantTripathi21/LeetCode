class Solution {
public:
    void print( vector<int> &nums){
        for( auto i:nums){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    int method1(vector<int>& nums){
        //using sorting-TC-NlogN + o(N)
        sort(nums.begin(),nums.end());
        int index = 0;
        int prevEle = nums[index++];
        int ans = 1;
        int subse = 1;
        while( index < nums.size()){
            if( nums[index] == prevEle +1){
                subse++;
                prevEle = nums[index];
            }
            else if( nums[index] == prevEle){
                index++;
                continue;
            }
            else{
                subse = 1;
                prevEle = nums[index];
            }
            ans = max( ans , subse);
            index++;
        }
        return ans;
    }

    int method2( vector<int>& nums){
        // using unordered set 
        // SC- o(N);
        //TC- o(2N) + o(N);
        int longest = 1;
        unordered_set<int>st;
        for( int i: nums){
            st.insert(i);
        }
        for( auto i: st){
            if( st.find(i -1) != st.end()){
                continue;
            }
            else{
                int x = 1;
                int temp = i;
                while( st.find( temp + 1) != st.end()){
                    temp = temp+1;
                    x++;
                }
                longest = max( longest,x);
            }
        }
        return longest;
    }
    int longestConsecutive(vector<int>& nums) {
        if( nums.size() == 0)return 0;
        return method2(nums);
    }
};
