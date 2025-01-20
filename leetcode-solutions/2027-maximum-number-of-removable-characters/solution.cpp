class Solution {
public:
    bool isSubsequence( string& s, string& p, vector<int>& nums, int k){
        unordered_map<int,int>isPresent;
        for( int i= 0; i< k; i++){
            isPresent[nums[i]] = 1;
        }
        int i = 0; //for s
        int j = 0; //for p
        while( i < s.size()) {
            if(isPresent.find(i) != isPresent.end()){
                i++;
                continue;
            }
            if( s[i] == p[j]){
                i++;
                j++;
            }
            else{
                i++;
            }
            if( j == p.size())return true;
        }
        return j == p.size();
    }
    int method( string& s, string& p , vector<int>& nums ) {
        int low = 1;
        int high = nums.size();
        int ans = 0;
        while( low <= high) {
            int mid = ( low + high) / 2;
            if( isSubsequence(s,p,nums,mid)){
                low = mid + 1;
                ans = max(ans,mid);
            }
            else high = mid - 1;
        }
        return ans;
    }
    int maximumRemovals(string s, string p, vector<int>& removable) {
        return method(s,p,removable);
    }
};
