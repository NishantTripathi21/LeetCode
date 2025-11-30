class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<string,int>mp;
        int n = nums.size();
        int res = INT_MAX;
        for(int i= 0; i< n; i++) {
            string st = to_string(nums[i]);
            if(mp.count(st)) {
                res = min(res, i - mp[st] );
            }
            reverse(st.begin(),st.end());
            int a = stoi(st);
            string str = to_string(a);
            ///cout<<" str: "<<str<<endl;
            mp[str] = i;
        }
        return res == INT_MAX ? -1 : res ;
    }
};
