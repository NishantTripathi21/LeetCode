class Solution {
public:
    int maxArea(vector<int>& height) {
        int start=0;
        int end=height.size() - 1;
        int maxi=INT_MIN;
        while(start<end){
            int heightOfContainer=min(height[start],height[end]);
            int width=end-start;
            int area=heightOfContainer * width;
            maxi=max(area,maxi);
            if(height[start] > height[end]){
                end--;
            }
            else {
                start++;
            }
        }
        return maxi;
    }
};
