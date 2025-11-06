class NumArray {
public:
    vector<int> segT;
    int n;
    void buildSegTree(vector<int>& nums,vector<int>& segT, int index, int start, int end) {
        if(start == end) {
            segT[index] = nums[start];
            return;
        }
        int mid = (start+end)/2;
        buildSegTree(nums,segT,2*index+1, start, mid);
        buildSegTree(nums,segT,2*index+2,mid+1,end);

        segT[index] = segT[index*2 + 1] + segT[2*index+2];
    }

    void updateSegTree(int index, int val, vector<int>& segT, int l, int r, int indexOfSegT) {
        if( l == r) {
            segT[indexOfSegT] = val;
            return;
        }

        int mid = (l+r)/2;
        if(mid < index) {
            updateSegTree(index,val,segT,mid+1,r,indexOfSegT*2+2);
        }
        else {
            updateSegTree(index,val,segT,l,mid,indexOfSegT*2+1);
        }

        segT[indexOfSegT] =  segT[2*indexOfSegT+1] + segT[2*indexOfSegT+2];
    }

    int querySum(int start, int end, int segIndex, int l, int r, vector<int>& segT) {
        if( r < start || l > end)return 0;

        if( l >= start && r <= end)return segT[segIndex];

        else {
            int mid = (l+r)/2;
            return querySum(start,end,segIndex*2+1,l,mid,segT)+ querySum(start,end,segIndex*2+2,mid+1,r,segT);
        }
    }
    NumArray(vector<int>& nums) {
        this->n = nums.size();
        this->segT.resize(4*n,0);
        int start = 0;
        int end = n-1;
        buildSegTree(nums, segT, 0, start, end);
    }
    
    void update(int index, int val) {
        updateSegTree(index,val,segT,0,n-1,0);
    }
    
    int sumRange(int left, int right) {
        return querySum(left,right,0,0,n-1,segT);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
