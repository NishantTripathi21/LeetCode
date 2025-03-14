class Solution {
public:
    int findLatestStep(vector<int>& arr, int m) {
        int n = arr.size();
        vector<int>binary(n+2,0);
        vector<int> size(n + 2, 0);
        unordered_map<int,int>groupCount;
        int latestPos = -1;
        for(int i= 0; i< n; i++) {
            int pos = arr[i];
            binary[pos] = 1;
            int leftSize = binary[pos-1] == 1 ? size[pos-1] : 0;
            int rightSize = binary[pos+1] == 1 ? size[pos+1]: 0;
            int totalSize = leftSize + rightSize + 1;

            if(leftSize > 0) {
                groupCount[leftSize]--;
            }
            if(rightSize) groupCount[rightSize]--;

            groupCount[totalSize]++;

            size[pos-leftSize] = size[pos+rightSize] = totalSize; // no need to update, only extreme updation will work

            if(groupCount[m] > 0) {
                latestPos = i + 1;
            }

        }
        return latestPos;

    }
};
