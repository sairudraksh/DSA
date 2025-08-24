class Solution {
public:
    const int M=1e9+7;
    long long find(long long base ,long long power){
        if(power==0) return 1;

        long long val=find(base,power/2);
        val=(val*val)%M;

        if(power%2==1){
            val=(val*base)%M;
        }
        return val;
    }
    int countGoodNumbers(long long n) {
        return (long long) find(5,(n+1)/2)*find(4,n/2)%M;
    }
};