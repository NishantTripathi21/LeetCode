class Solution {
public:
    int countLessEqual(vector<vector<int>>& matrix, int mid, int n) {
        int count = 0, row = n - 1, col = 0;
        while (row >= 0 && col < n) {
            if (matrix[row][col] <= mid) {
                count += row + 1; // All elements in this column above the current row are also ≤ mid
                col++;
            } else {
                row--; // Move up to find smaller values
            }
        }
        return count;
    }

    int method( vector<vector<int>>& matrix, int k) {
        // using BS on answer
        int n = matrix.size();
        int low = matrix[0][0], high = matrix[n-1][n-1];
        int result = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int count = countLessEqual(matrix, mid, n);
            //cout<<" mid: "<<mid<<" low: "<<low<<" high: "<<high<<" count: "<<count<<endl;
            if (count < k) {
                low = mid + 1;
            }
            else{
                result = mid;
                high = mid-1;
            }
        }
        return result;
    }

    int method2(vector<vector<int>>& matrix, int k) {
        // using Priority queue
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap; // value,row,col
        int m = matrix.size();
        int n = matrix[0].size();
        // insert one row col in minHeap
        for( int i= 0; i< m; i++) {
            minHeap.push({matrix[i][0],i,0});
        }

        int popped = 1;
        while( popped < k) {
            auto top = minHeap.top();
            minHeap.pop();
            popped++;
            int newCol = top[2]+1;
            int newRow = top[1];
            if( newCol == n)continue;
            int newEle = matrix[newRow][newCol];
            minHeap.push({newEle,newRow,newCol});
        }
        return minHeap.top()[0];
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        return method2( matrix, k);
    }
};
