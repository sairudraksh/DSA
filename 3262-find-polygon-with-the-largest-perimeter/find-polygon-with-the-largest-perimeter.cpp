class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<long long>prefix(n,nums[0]);

        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+nums[i];
        }
    
        int j=1;
        long long ans=-1;
        while(j<n){
            if(prefix[j-1]>nums[j]){
                ans=prefix[j-1]+nums[j];
            }
            j++;
        }
        return ans;

    }
};