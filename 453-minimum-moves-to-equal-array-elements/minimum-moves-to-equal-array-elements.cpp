class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int num=nums[0];
        int ans=0;
        for(int i=0;i<nums.size();i++){
            ans+=(nums[i]-num);
        }
        return ans;
    }
};