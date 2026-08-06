class Solution {
public:
    bool isTrue(int n,int t){
        int sum=1;
        while(n>0){
            int num=n%10;
            sum*=num;
            n=n/10;
        }
        if(sum%t==0) return true;
        return 0;
    }
    int smallestNumber(int n, int t) {
        for(int i=n;i<=n+10;i++){
            if(isTrue(i,t)) return i;
        }
        return -1;
    }
};