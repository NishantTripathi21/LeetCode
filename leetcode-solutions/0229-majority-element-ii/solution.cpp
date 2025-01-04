class Solution {
public:
    vector<int> method1(vector<int>& nums){
        // SC- 0(N);
        // TC- 0(N);
        unordered_map<int , int >mp;
        set<int>st;
        int size = nums.size();
        int freq = size / 3;
        int index = 0;
        //cout<<" index: "<<index<<" freq: "<<freq<<" size: "<<size<<endl;
        while ( index < nums.size()){
            int element = nums[index];
            mp[element]++;
            if( mp.find(element) != mp.end()){
                if(mp[element] > freq){
                    st.insert(element);
                }
            }
            index++;
        }
        vector<int>ans;
        for( int i: st){
            ans.push_back(i);
        }
        return ans;
    }

    vector<int> method2( vector<int>& nums){
        // modification in Moore's algo
        int count1 = 0;
        int count2=0;
        int ele1,ele2 = INT_MIN;
        // count for tracking frequency of element
        // element variable to store majority element
        /*  If count1 is 0 and the current element is not el2 then store the current element of
            the array as el1 along with increasing the cnt1 value by 1.
            If cnt2 is 0 and the current element is not el1 then store the current element of the
            array as el2 along with increasing the cnt2 value by 1.
            If the current element and el1 are the same increase the cnt1 by 1.
            If the current element and el2 are the same increase the cnt2 by 1.
            Other than all the above cases: decrease cnt1 and cnt2 by 1. */
        int index = 0;
        while( index < nums.size()){
            if( count1 == 0 && nums[index] != ele2){
                ele1 = nums[index];
                count1++;
            }
            else if( count2 == 0 && nums[index] != ele1){
                ele2 = nums[index];
                count2++;
            }
            else if( nums[index] == ele1){
                count1++;
            }
            else if( nums[index] == ele2){
                count2++;
            }
            else{
                count1--;
                count2--;
            }
            index++;
        }
        // set counts = 0 and reiterate over array to verify both ele1 and ele2 are majority element
        count1 = 0;count2 = 0;
        for( int i = 0; i<nums.size(); i++){
            if( nums[i] == ele1){
                count1++;
            }
            if( nums[i] == ele2){
                count2++;
            }
        }
        int minFre = int(nums.size()) / 3;
        vector<int>ans;
        if( count1 > minFre){
            ans.push_back(ele1);
        }
        if( count2 > minFre){
            ans.push_back(ele2);
        }
        return ans;

    }
    vector<int> majorityElement(vector<int>& nums) {
        return method2(nums);
    }
};
