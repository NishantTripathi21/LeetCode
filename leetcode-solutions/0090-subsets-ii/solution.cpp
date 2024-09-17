class Solution {
public:
    void usingRec(vector<int>& nums, vector<vector<int>>& ans, vector<int>& temp,int index){
        if(index==nums.size()){
            ans.push_back(temp);
            return;
        }
        //exclude
        usingRec(nums,ans,temp,index+1);
        //include
        temp.push_back(nums[index]);
        usingRec(nums,ans,temp,index+1);
        temp.pop_back();
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>temp;
        usingRec(nums,ans,temp,0);
        set<vector<int>>unique;
        for(auto i:ans){
            unique.insert(i);
        }
        ans.clear();
        for(auto i:unique){
            ans.push_back(i);
        }
        return ans;
    }
};
