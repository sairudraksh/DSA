class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long long ans=0;
        
        for(int i=0;i<=1000000;i++){
            long long t=total-(cost1*i);
            if(t<0) break;
            long long pencount=i;
            long long pencilcount=0;
            int count=1;
            count+=(t/cost2);
            ans+=count;
        }
        return ans;
    }
};