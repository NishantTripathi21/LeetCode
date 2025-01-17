class Solution {
public:
    int findMax( vector<vector<int>>& nums,int mid){
        int max = -1;
        int index = 0;
        for( int i= 0; i< nums.size();i++){
            if( nums[i][mid] > max ){
                max = nums[i][mid];
                index = i;
            }
        }
        return index;
    }
    vector<int> method1( vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int low = 0;
        int high = n -1;
        while( low <= high){
            int mid = (low + high) / 2;
            int maxRowIndex = findMax( mat,mid);
            int left = mid - 1 >= 0 ? mat[maxRowIndex][mid-1]:-1;
            int right = mid + 1 < n ? mat[maxRowIndex][mid+1]: -1;
            if( mat[maxRowIndex][mid] > left && mat[maxRowIndex][mid] > right){
                return { maxRowIndex, mid};
            }
            else if( mat[maxRowIndex][mid] < left){
                high = mid -1;
            }
            else low = mid+1;
        }
        return{-1,-1};

    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        return method1(mat);
    }
};
