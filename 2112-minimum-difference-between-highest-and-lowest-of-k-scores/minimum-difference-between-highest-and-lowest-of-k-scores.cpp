class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        if(k==1) return 0;
        int minimum=INT_MAX;
        for(int i=0;i+k-1<n;i++){
            minimum=min(minimum,nums[i+k-1]-nums[i]);
        }
        return minimum;
    }
};