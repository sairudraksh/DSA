class Solution {
public:
    long long maximumProduct(vector<int>& nums, int m) {
        int n=nums.size();
        vector<int>largest(n,nums[n-1]);
        vector<int>smallest(n,nums[n-1]);

        for(int i=n-2;i>=0;i--){
            largest[i]=max(nums[i],largest[i+1]);
            smallest[i]=min(nums[i],smallest[i+1]);
        }

        long long maximum=LLONG_MIN;

        for(int i=0;i<n;i++){
            int idx=(i+m)-1;
            if(idx>=n) break;
            maximum=max(maximum,1LL*nums[i]*largest[idx]);
            maximum=max(maximum,1LL*nums[i]*smallest[idx]);
        }
        return maximum;
    }
};