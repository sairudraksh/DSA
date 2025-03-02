class Solution {
public:
    int countbits(int n){
        int count=0;
        while(n>0){
            count++;
            n=n&(n-1);
        }
        return count;
    }
    int hammingDistance(int x, int y) {
        int a=countbits(x^y);
        return a;
    }
};