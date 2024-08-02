class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int>arr;
        int i=0;
        int j=0;
        while(i<m && j<n){
            if(nums1[i]>nums2[j]){
                arr.push_back(nums2[j]);
                j++;
            }
            else if(nums1[i]<nums2[j]){
                arr.push_back(nums1[i]);
                i++;
            }
            else if(nums1[i]==nums2[j]){
                arr.push_back(nums1[i]);
                i++;
            }
        }
        while (i < m) {
        arr.push_back(nums1[i]);
        i++;
    }

    // Add remaining elements from nums2, if any
    while (j < n) {
        arr.push_back(nums2[j]);
        j++;
    }
        for(int k=0;k<arr.size();k++){
            nums1[k]= arr[k];
        }
       // nums1=arr;
    }
};
