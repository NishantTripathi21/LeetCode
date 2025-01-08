class Solution {
public:
    int method1( vector<int>& plants, int capA, int capB){
        int A= capA;
        int B =capB;
        int left = 0;
        int right = plants.size()-1;
        int refills=  0;
        while( left < right){
            int plantA= plants[left];
            int plantB= plants[right];
            if( A < plantA){
                A = capA;
                refills++;
            }
            if( B < plantB){
                B = capB;
                refills++;
            }
            A -= plantA;
            B -= plantB;
            left++;
            right--;
        }
        if( left == right){
            if( A >= B){
                if( A < plants[left]){
                    refills++;
                }
                A -= plants[left];
            }
            else{
                if( B < plants[right]){
                    refills++;
                }
                B -= plants[right];
            }
        }
        return refills;
    }
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        return method1(plants, capacityA, capacityB);
    }
};
