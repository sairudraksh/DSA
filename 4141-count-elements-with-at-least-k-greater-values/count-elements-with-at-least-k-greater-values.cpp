class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int count=0;
        for(int i=0;i<n;i++){
            int x=(n-1)-i;
            int l=i;
            int idx = upper_bound(nums.begin(), nums.end(), nums[i]) - nums.begin();// givees the first index where vallue is greaterthan nums[i]
            x=n-idx;
            if(x>=k) count++;
        }
        return count;
    }
};