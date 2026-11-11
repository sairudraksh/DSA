class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long x=1LL*cost1+1LL*cost2;
        long long num=min(1LL*x,1LL*costBoth);
        long long freq=min(1LL*need1,1LL*need2);

        long long ans=0;
        ans+=(freq*num);

        need1-=freq;
        need2-=freq;

        if(need1>0){
            num=min(1LL*cost1,1LL*costBoth);
            ans+=(need1*num);
        }
        if(need2>0){
            num=min(1LL*cost2,1LL*costBoth);
            ans+=(need2*num);
        }
        return ans;
    }
};