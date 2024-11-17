class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fives=0;
        int tens=0;
        int index=0;
        int twentys=0;
        bool ans = true;
        while(index < bills.size()){
            int bill = bills[index];
            // if bill is 5- always acceptable
            if( bill == 5){
                fives++;
                ans= true;
            }
            // if bill is 10, acceptable only if vendor has 5 dollar to return
            else if( bill == 10){
                if( fives < 1){
                    return false;
                    break;
                }
                else{
                    tens++;
                    fives--;
                }
            }
            // if bill is 20_ acceptable only if vendor can return 15- two ways to return- 10+5 or 5+5+5
            else{
                if( fives >= 3 || ( tens >= 1 && fives >= 1)){
                    twentys++;
                    if(( tens >= 1 && fives >= 1 ) ){
                        fives--;
                        tens--;
                    }
                    else{
                        fives = fives - 3;
                    }
                }
                else{
                    return false;
                    break;
                }
            }
            index++;
        }
        return true;
    }
};
