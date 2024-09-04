class Solution {
public:
    void mergeTwoArrays(vector<int>nums1,vector<int> nums2, vector<int> &ans){
        int start1=0;
        int start2=0;
        while(start1 < nums1.size() && start2 < nums2.size()){
            if(nums1[start1] > nums2[start2]){
                ans.push_back(nums2[start2]);
                start2++;
            }
            else if(nums1[start1] < nums2[start2]){
                ans.push_back(nums1[start1]);
                start1++;
            }
            else{
                ans.push_back(nums1[start1]);
                ans.push_back(nums2[start2]);
                start1++;
                start2++;
            }
        }
        while(start1 < nums1.size()){
            ans.push_back(nums1[start1]);
            start1++;
        }
        while(start2 < nums2.size()){
            ans.push_back(nums2[start2]);
            start2++;
        }
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        mergeTwoArrays(nums1,nums2,ans);
        int size=ans.size();
        double medianAns;
        if(size & 1){
            medianAns=ans[size / 2];
        }
        else{
            medianAns= float(ans[size/2 - 1] + ans[ size/2 ]) / 2;
        }
        return medianAns;
    }
};
