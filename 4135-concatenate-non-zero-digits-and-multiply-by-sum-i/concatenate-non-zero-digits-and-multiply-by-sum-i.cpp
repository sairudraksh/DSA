class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum=0;
        long long num=0;

        while(n>0){
            int x=n%10;
            sum+=x;
            if(x>0){
                num=(num*10)+x;
            }
            n=n/10;
        }
        int ans=0;
        while(num>0){
            int x=num%10;
            ans=ans*10+x;
            num=num/10;
        }
        return sum*ans;
    }
};