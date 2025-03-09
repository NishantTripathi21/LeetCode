class Solution {
public:
    vector<long long> findMaxSum(vector<int>& arr1, vector<int>& arr2, int k) {
        int size = arr1.size();
        vector<long long> result(size, 0);
        vector<int> indices(size);

        for (int i = 0; i < size; i++) {
            indices[i] = i;
        }

        sort(indices.begin(), indices.end(), [&](int a, int b) {
            return arr1[a] < arr1[b];
        });

        priority_queue<int, vector<int>, greater<int>> minHeap;
        long long sumTracker = 0;
        int i = 0;

        while (i < size) {
            int j = i;
            while (j < size && arr1[indices[j]] == arr1[indices[i]]) {
                result[indices[j]] = sumTracker;
                j++;
            }
            for (int p = i; p < j; p++) {
                int currIdx = indices[p];
                minHeap.push(arr2[currIdx]);
                sumTracker += arr2[currIdx];
                if (minHeap.size() > k) {
                    sumTracker -= minHeap.top();
                    minHeap.pop();
                }
            }
            i = j;
        }

        return result;
    }
};
