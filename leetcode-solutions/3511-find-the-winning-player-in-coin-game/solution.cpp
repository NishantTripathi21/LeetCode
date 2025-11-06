class Solution {
public:
    string winningPlayer(int x, int y) {
        bool flag= true; //alice
        while(true) {
            if(flag) {
                if(x >= 1 && y >= 4) {
                    x--;
                    y -= 4;
                }
                else return "Bob";
            }
            else {
                if(x >= 1 && y >= 4) {
                    x--;
                    y -= 4;
                }
                else return "Alice";
            }
             flag = !flag;
        }
        if(flag)return "Bob";
        return "Alice";
    }
};
