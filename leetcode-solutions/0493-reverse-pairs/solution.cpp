class Solution {
public:
    void merge(vector<int> &arr, int low, int mid, int high) {
        vector<int> temp; // temporary array
        int left = low;      // starting index of left half of arr
        int right = mid + 1;   // starting index of right half of arr
    
        //storing elements in the temporary array in a sorted manner//
        while (left <= mid && right <= high) {
            if (arr[left] < arr[right]) {
                temp.push_back(arr[left]);
                left++;
            }
            else {
                temp.push_back(arr[right]);
                right++;
            }
        }
    
        // if elements on the left half are still left //
    
        while (left <= mid) {
            temp.push_back(arr[left]);
            left++;
        }
    
        //  if elements on the right half are still left //
        while (right <= high) {
            temp.push_back(arr[right]);
            right++;
        }
    
        // transfering all elements from temporary to arr //
        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }
    }
    
    int countPairs(vector<int>&arr, int low,int high,int mid){
        //int left = low;
        int right = mid+1;
        int count = 0;
        for( int i = low; i<=mid; i++){
            while( right <= high && arr[i] > (long long)2*arr[right]){
                right++;
                //cout<<" count: "<<count<<" left: "<<i<<" right: "<<right-1<<endl;
            }
            count += right - (mid +  1) ;
        }
        return count;
    }

    int mergeSort(vector<int> &arr, int low, int high) {
        if (low >= high) return 0;
        int count = 0;
        int mid = (low + high) / 2 ;
        count += mergeSort(arr, low, mid);  // left half
        count += mergeSort(arr, mid + 1, high); // right half
        count += countPairs(arr,low,high,mid);
        merge(arr, low, mid, high);  // merging sorted halves
        return count;
    }
    int reversePairs(vector<int>& nums) {
        // intution derieved from count inversion question of gfg.- slight modification is made.
        return mergeSort(nums,0,nums.size()-1);
    }
};
