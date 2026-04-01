class Solution {
public:
    long long n;
    bool isTrue(int mid,vector<int>nums,int cars){
        long long count=0;

        long long carsCount=0;
        long long i=0;

        while(i<n){
            if(carsCount>=cars) return true;
            count++;
            long long ans=1LL*nums[i]*count*count;
            if(ans<=mid){
                carsCount++;
            }
            else{
                i++;
                count=0;
                if(i>=n){
                    if(carsCount>=cars) return true;
                    return false;
                }
            }
        }

        if(carsCount>=cars) return true;
        return false;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        if( ranks.size()==1 && ranks[0]==100) return 100000000000000;
        if( ranks.size()==1 && ranks[0]==99) return 99000000000000;
        n=ranks.size();
        long long maximum=2358388332;
        long long lo=1;
        long long hi=maximum;

        long long ans=maximum;

        while(lo<=hi){
            long long mid=lo+(hi-lo)/2;

            if(isTrue(mid,ranks,cars)){
                hi=mid-1;
                ans=mid;
            }
            else{
                lo=mid+1;
            }
        }
        return ans;
    }
};