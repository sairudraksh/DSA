class Solution {
public:
    bool isTrue(int buckets,int num,int pigs){
        long long states=1;
        //pow(num+1,pigs)
        for(int i=1;i<=pigs;i++){
            states*=(num+1);

            if(states>=buckets) return true;
        }
        return false;

    }
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        if(buckets==1) return 0;
        int lo=0;
        int hi=buckets;

        int ans=buckets;

        while(lo<=hi){
            int mid=lo+(hi-lo)/2;

            if(isTrue(buckets,minutesToTest/minutesToDie,mid)){
                ans=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }
        return ans;
    }
};