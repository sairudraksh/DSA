class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int l=0;
        int r=0;
        long long minsum=LLONG_MAX;
        int n=nums.size();
        while(r<n){
            long long num=nums[l];
            long long numm=k*num;
            if(nums[r]<=numm){
                long long count1=l;
                long long count2=(n-1)-r;
                long long ans=count1+count2;
                minsum=min(minsum,ans);
                r++;
            }
            else l++;
        }
        if(minsum==LLONG_MAX) return 0;
        return minsum;
    }
};