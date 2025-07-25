class Solution {
public:
    int digitSum(int n) {
        int sum = 0;
        while(n) {
            sum += n%10;
            n = n/10;
        }
        cout<<sum;
        return sum;
    }
    int product(int n) {
        int sum = 1;
        while(n) {
            sum *= n%10;
            n = n/10;
        }
        cout<<" "<<sum;
        return sum;
    }
    bool checkDivisibility(int n) {
        int a = digitSum(n);
        int b = product(n);
        if(n%(a+b) == 0 )return true;
        return false;
    }
};
