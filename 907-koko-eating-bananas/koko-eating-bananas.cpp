class Solution {
public:
    bool isTrue(vector<int>& piles, long long mid,int h){
        long long count=0;
        for(int i=0;i<piles.size();i++){
            count+=((long long)piles[i]/mid);
            if((long long)piles[i]%mid!=0) count++;
        }
        return count<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();

        long long lo=1;
        long long hi=0;

        for(int i=0;i<n;i++){
            hi=max(hi,(long long)piles[i]);
        }
        int ans=hi;
        while(lo<=hi){
            long long mid=lo+(hi-lo)/2;

            if(isTrue(piles,mid,h)){
                hi=mid-1;
                ans=mid;
            }
            else lo=mid+1;
        }
        return ans;
    }
};