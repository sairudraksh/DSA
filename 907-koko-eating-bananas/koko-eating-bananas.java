class Solution {
    public boolean isTrue(int[] piles, long mid,int h){
        long count=0;
        for(int i=0;i<piles.length;i++){
            count+=((long)piles[i]/mid);
            if((long)piles[i]%mid!=0) count++;
        }
        return count<=h;
    }
    public int minEatingSpeed(int[] piles, int h) {
        int n=piles.length;

        long lo=1;
        long hi=0;

        for(int i=0;i<n;i++){
            hi=Math.max(hi,(long)piles[i]);
        }
        long ans=hi;
        while(lo<=hi){
            long mid=lo+(hi-lo)/2;

            if(isTrue(piles,mid,h)){
                hi=mid-1;
                ans=mid;
            }
            else lo=mid+1;
        }
        return (int)ans;
    }
}