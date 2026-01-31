class Solution {
public:
    int reverse(int n){
        int num=0;
        while(n>0){
            int x=n%10;
            num=(num*10)+x;
            n=n/10;
        }
        return num;
    }
    int mirrorDistance(int n) {
        int num=reverse(n);

        return abs(n-num);
    }
};