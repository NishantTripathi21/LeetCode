
class Solution {
public:
    int smallestAbsent(vector<int>& nums) {
        int sum = 0;
        for(int i: nums) {
            sum+=i;
        }
        int n = nums.size();
        int avg = floor((double)sum/(double)n) + 1;
        unordered_set<int>mp(nums.begin(),nums.end());
        cout<<avg;
        while(mp.size() > 0) {
            if(mp.find(avg) != mp.end()) {
                mp.erase(avg);
            }
            else{
                if(avg>0) return avg;
            }
            avg++;
            if(avg > 101 ) break;
        }
        return 1;
    }
};



