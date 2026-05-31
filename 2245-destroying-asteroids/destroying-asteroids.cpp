class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<long long>prefix(n,0);
        prefix[0]=mass+nums[0];
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+nums[i];
        }
        if(nums[0]>mass) return false;
        for(int i=1;i<n;i++){
            if(prefix[i-1]<nums[i]) return false;
        }
        return true;
    }
};