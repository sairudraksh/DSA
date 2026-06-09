class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long n=nums.size();
        long long maximum=-1;
        long long minimum=LLONG_MAX;

        for(int i=0;i<n;i++){
            maximum=max(maximum,(long long)nums[i]);
            minimum=min(minimum,(long long)nums[i]);
        }
        long long ans=(maximum-minimum)*k;
        return ans;
    }
};