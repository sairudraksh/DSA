class Solution {
public:
    int maxCoins(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int i=0;
        int j=n-1;
        int ans=0;
        while(i<j){
            int a=nums[i];
            i++;
            int b=nums[j];
            j--;
            int c=nums[j];
            ans+=nums[j];
            j--;
        }
        return ans;
    }
};