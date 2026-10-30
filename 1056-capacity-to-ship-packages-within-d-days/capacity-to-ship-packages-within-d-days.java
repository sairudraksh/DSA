class Solution {
    public boolean isTrue(int[] weights,long mid,int days){
        long count=0;
        long curr=0;

        for(int i=0;i<weights.length;i++){
            if((long)weights[i]>mid) return false;
            else if((long)weights[i]+curr>mid){
                count++;
                curr=weights[i];
            }
            else curr+=weights[i];
        }
        count++;
        return count<=days;
    }
    public int shipWithinDays(int[] weights, int days) {
        int n=weights.length;
        long lo=1;
        long hi=0;
        for(int i=0;i<n;i++){
            hi+=weights[i];
        }
        long ans=hi;

        while(lo<=hi){
            long mid=lo+(hi-lo)/2;
            if(isTrue(weights,mid,days)){
                hi=mid-1;
                ans=mid;
            }
            else lo=mid+1;
        }
        return (int)ans;

    }
}