class Solution {
public:
    int MountainIndex(vector<int>&arr){
        int start=0;
        int end=arr.size()-1;
        int mid=start+(end-start)/2;
        while(start< end){
            if(arr[mid]<arr[mid+1] && mid+1<arr.size()){
                start=mid+1;

            }
            else{
                end=mid;
            }
            mid=start+(end-start)/2;
        }
        return end;
    }
    bool monotonicIn(vector<int>&arr,int i, int j){
        bool ans=false;
        while( i<j){
            if(arr[i]<arr[i+1]){
            ans=true;
            i++;
            
            }
            else{
                ans=false;
                break;
            }

        }
        return ans;
    }

    bool monotonicDc(vector<int>&arr,int i, int j){
        bool ans=false;
        while( i<j){
            if(arr[i]>arr[i+1]){
            ans=true;
            i++;
           
            }
            else{
                ans=false;
                break;
            }

        }
        return ans;
    }
    bool validMountainArray(vector<int>& arr) {
        
        int index=MountainIndex(arr);
        bool ans1=monotonicIn(arr,0,index);
        bool ans2=monotonicDc(arr,index,arr.size()-1);
        return ans1 && ans2;

    }
};
