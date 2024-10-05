class Solution {
public:
    bool isPossible(string& one, string& two){
        if(one.size() != two.size() +1){
            return false;
        }
        int first=0;
        int second=0;
        while(first < one.size()){
            if(one[first] == two[second]){
                first++;
                second++;
            }
            else{
                first++;
            }
        }
        if(first==one.size() && second==two.size())return true;
        return false;
    }
    //using the code of Longest increasing subsequence wiht some modifications in conditions
    int usingOtherMethod(vector<string>& nums){
        vector<int>dp(nums.size()+1,1);
        int maxi=1;
        for(int index=0;index<nums.size();index++){
            for(int prev=0;prev < index;prev++){
                if(isPossible(nums[index],nums[prev]) && dp[index] < dp[prev]+1){
                    dp[index]=dp[prev] + 1; 
                }
            }
            if(dp[index] > maxi){
                maxi=dp[index];
            }
        }
        return maxi;
    }
    static bool comp(string& s1, string& s2){
        return s1.size() < s2.size();
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),comp);
        return usingOtherMethod(words);
    }
};
