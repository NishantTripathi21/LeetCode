/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int usingRecursion( int start,int end){
        if(start > end)return -1;
        int mid=(start+end)/2;
        if( guess(mid)==0)return mid;
        else if( guess(mid) == -1){
            return usingRecursion(start,mid-1);
        }
        else{
            return usingRecursion(mid+1,end);
        }
    }
    int Method1(int n){
        int start=1;
        int end=n;
        int mid=start +(end-start)/2;
        while( start <= end){
            if(guess(mid)==0){
                return mid;
            }
            else if( guess(mid) == -1){
                end=mid-1;
            }
            else{
                start=mid+1;
            }
            mid=start + (end - start)/2;
        }
        return -1;
    }
    int guessNumber(int n) {
        return Method1(n);
    }
};
