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
    int minBitFlips(int start, int goal) {
        int a=countbits(start^goal);
        return a;
    }
};