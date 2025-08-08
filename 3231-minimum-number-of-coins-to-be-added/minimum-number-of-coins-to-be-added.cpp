class Solution {
public:
    int minimumAddedCoins(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());

        int i=0;
        long long maxans=0;
        int count=0;

        while(maxans<target){
            if(i<nums.size() && nums[i]<=maxans+1){
                maxans+=nums[i];
                i++;
            }
            else{
                maxans+=maxans+1;
                count++;
            }
        }

        return count;
    }
};