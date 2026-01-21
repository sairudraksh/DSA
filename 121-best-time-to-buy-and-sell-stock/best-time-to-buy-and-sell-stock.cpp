class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int n=nums.size();
        int curr=nums[0];
        int maximum=0;
        for(int i=1;i<n;i++){
            if(nums[i]<curr){
                curr=nums[i];
            }
            else{
                maximum=max(maximum,nums[i]-curr);
            }
        }
        return maximum;
    }
};