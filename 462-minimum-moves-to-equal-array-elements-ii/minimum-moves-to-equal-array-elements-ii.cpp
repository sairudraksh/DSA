class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        if(n==1) return 0;
        int diff=(nums[n/2]+nums[(n/2)-1])/2;
        if(n%2!=0){
            diff=nums[n/2];
        }
        if(nums[n-1]==nums[0]) return 0;
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=abs(nums[i]-diff);
        }
        return ans;
    }
};