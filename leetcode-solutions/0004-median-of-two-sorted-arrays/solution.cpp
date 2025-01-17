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
    double method2( vector<int>& nums1, vector<int>& nums2){
        int n1 = nums1.size();
        int n2 = nums2.size();
        if( n1 > n2)return method2( nums2, nums1);
        int low = 0;
        int high = n1;
        int left = (n1+n2+1) /2;
        while( low <= high){
            int mid1 = (low+high)/2;
            int mid2 = left - mid1;
            int l1 = INT_MIN;
            int l2 = INT_MIN;
            int r1 = INT_MAX;
            int r2 = INT_MAX;
            if( mid1-1 >= 0)l1 = nums1[mid1-1];
            if( mid2-1 >= 0)l2 = nums2[mid2-1];
            if( n1 > mid1)r1 = nums1[mid1];
            if(n2 > mid2)r2 = nums2[mid2];
            if( l1 <= r2 && l2 <= r1){
                if( (n1+n2) & 1)return max(l1,l2);
                else return ( (double) (max(l1,l2)+min(r1,r2)) /  2.0);
            }
            else if( l1 > r2){
                high = mid1 -1;
            }
            else low = mid1+1;
        }
        return 0;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // vector<int>ans;
        // mergeTwoArrays(nums1,nums2,ans);
        // int size=ans.size();
        // double medianAns;
        // if(size & 1){
        //     medianAns=ans[size / 2];
        // }
        // else{
        //     medianAns= float(ans[size/2 - 1] + ans[ size/2 ]) / 2;
        // }
        // return medianAns;
        return method2( nums1,nums2);
    }
};
