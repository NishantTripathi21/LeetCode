class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n= arr.size();
        int s=0;
        int end=n-1;
        int mid= (s+end)/2;
        while(s<end){
            if(arr[mid]<arr[mid+1]){
                s=mid+1;
            }
            else{
                end=mid;
            }
            mid=(s+end)/2;
        }
        return s;
        
    }
};
