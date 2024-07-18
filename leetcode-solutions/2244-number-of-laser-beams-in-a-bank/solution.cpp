class Solution {
public:

    int getDevice(string& binary){
        int c=0;
        for(auto st:binary){
            c+=st-'0';
        }
        return c;
    }
    int numberOfBeams(vector<string>& bank) {
        vector<int>devices;
        for(auto binary: bank){
            devices.push_back(getDevice(binary));
        }
       int ans=0;
        for(int i=0;i<devices.size();i++){
            int j=i+1;
            while(j<devices.size()){
                ans=ans+ devices[i]*devices[j];
                if(devices[j]==0){
                    j++;
                }
                else{
                    break;
                }
            }
        }
        return ans;
        
    }
};
