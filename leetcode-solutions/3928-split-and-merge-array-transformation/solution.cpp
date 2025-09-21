class Solution {
public:
    int minSplitMerge(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        if(nums1 == nums2){
            return 0;
        }
        queue<pair<vector<int>, int>>q;
        set<vector<int>>visited;
        q.push({nums1, 0});
        visited.insert(nums1);
    
        while(!q.empty()){
            auto currentPerm = q.front().first;
            int dist = q.front().second;
            q.pop();    
            for(int l = 0; l < n; ++l){
                for(int r = l; r < n; ++r){
                    vector<int> sbary(currentPerm.begin() + l, currentPerm.begin() + r + 1);
                    vector<int> rp;
                    rp.insert(rp.end(), currentPerm.begin(), currentPerm.begin() + l);
                    rp.insert(rp.end(), currentPerm.begin() + r + 1, currentPerm.end());
                    for(int i = 0; i <= rp.size(); ++i){
                        vector<int> newPerm = rp;
                        newPerm.insert(newPerm.begin() + i, sbary.begin(), sbary.end());
                        if(newPerm == nums2){
                            return dist + 1;
                        }
                        if(visited.count(newPerm) == 0){
                            visited.insert(newPerm);
                            q.push({newPerm, dist + 1});
                        }
                    }
                }
            }
        }
        return -1;
    }
};
