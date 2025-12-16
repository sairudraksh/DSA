class Solution {
public:
    int maxProfit(vector<int>& nums){
        int n=nums.size();
        int profit=0;
        int buy=nums[0];
        for(int i=1;i<n;i++){
            if(buy>nums[i]){
                buy=nums[i];
            }
            else{
                profit=max(profit,(nums[i]-buy));
            }
        }
        return profit;
    }
};