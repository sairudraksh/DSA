class Solution {
public:
    bool isTrue(long long minValue,vector<long long>&prefix,int r,int k){
        int i=0;
        int n=prefix.size();
        vector<long long>diff(n+1,0);
        long long extra=0;
        while(i<prefix.size()){
            extra+=diff[i];
           long long curr=prefix[i]+extra;

            if(curr>=minValue){
                i++;
            }
            else{
               long long left=minValue-curr;

                if(left<=k){
                    k=k-left;
                    extra+=left;
                    long long l=i;
                    long long r1=min(n-1,i+2*r);

                    if(r1+1<n){
                        diff[r1+1]-=left;
                    }
                    i++;
                }
                else return false;
            }
        }
        return true;
    }
    long long maxPower(vector<int>& nums, int r, int k) {
        int n=nums.size();
        vector<long long>prefix(n,nums[0]);
        vector<long long>suffix(n,nums[n-1]);

        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+nums[i];
        }

        for(int i=n-2;i>=0;i--){
            suffix[i]=suffix[i+1]+nums[i];
        }

        vector<long long>power(n,0);
        long long maximum=LLONG_MIN;
        for(int i=0;i<n;i++){
            long long prevIdx=max(0,i-r);
            long long nextIdx=min(n-1,i+r);
            long long currSum=0;
            long long leftSum=0;
            long long rightSum=0;
            if(prevIdx>=0){
                if(prevIdx==0){
                    leftSum=prefix[i];
                }
                else leftSum=prefix[i]-prefix[prevIdx-1];
            }
            if(nextIdx<n){
                if(nextIdx==n-1){
                    rightSum=suffix[i];
                }
                else rightSum=suffix[i]-suffix[nextIdx+1];
            }
            currSum=leftSum+rightSum;
            if(leftSum>0 && rightSum>0){
                currSum-=nums[i];
            }

            power[i]=currSum;
            maximum=max(maximum,power[i]);
        }

        long long lo=0;
        long long hi=maximum+k;
        long long ans=-1;
        while(lo<=hi){
            long long mid=lo+(hi-lo)/2;

            if(isTrue(mid,power,r,k)){
                ans=mid;
                lo=mid+1;
            }
            else hi=mid-1;
        }
        return ans;


    }
};