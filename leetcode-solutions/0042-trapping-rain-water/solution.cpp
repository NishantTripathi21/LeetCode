class Solution {
public:
    vector<int> rightGreatest(vector<int>&height){
        //this function stores greatest number in the right of a index in an array
        vector<int>right(height.size(),-1);
        for(int i=height.size()-1;i>=0;i--){
            if(i==height.size()-1)right[i]=height[i];
            else{
                right[i]=max(height[i],right[i+1]);
            }
        }
        cout<<"right ";
        for(auto i:right)cout<<i<<" ";
        return right;
    }
    vector<int> leftGreatest(vector<int>&height){
        //this function stores greatest number in the left of a index in an array, we can reduce this space 
        vector<int>left(height.size(),-1);
        for(int i=0;i<height.size();i++){
            if(i==0)left[i]=height[i];
            else{
                left[i]=max(height[i],left[i-1]);
            }
        }
        cout<<"left ";
        for(auto i:left)cout<<i<<" ";
        return left;
    }
    int trappedWater(vector<int>&height){
        auto right=rightGreatest(height);
        //auto left=leftGreatest(height);
        int leftMax=height[0];// we can use leftMax variable to keep track of leftGreatest element while we traverse to find
        // ans in trappedWater fucntion
        int ans=0;
        for(int i=0;i<height.size();i++){
            leftMax=max(leftMax,height[i]);
            if(height[i] < leftMax && height[i] < right[i]){
                ans+=min(leftMax,right[i]) - height[i];
            }
        }
        return ans;
    }
    int trap(vector<int>& height) {
        return trappedWater(height);
    }
};
