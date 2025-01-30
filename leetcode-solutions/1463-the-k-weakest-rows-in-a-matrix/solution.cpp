class Solution {
public:
    int countSoldiers(vector<int>& row) {
        int left = 0, right = row.size()-1;
        int ans = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if(row[mid] == 1){
                ans = mid+1;
                left = mid + 1;
            }   
            else{
                right = mid-1;
            }
        }
        //cout<<" ans: "<<ans<<endl;
        return ans;
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        for (int i = 0; i < m; i++) {
            int soldiers = countSoldiers(mat[i]);
            minHeap.push({soldiers, i}); 
        }

        vector<int> result;
        for (int i = 0; i < k; i++) {
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return result;
    }
};
