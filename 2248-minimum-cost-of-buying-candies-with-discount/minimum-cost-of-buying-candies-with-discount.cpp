class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        reverse(nums.begin(),nums.end());

        int i=0;
        int count=0;
        int pivot=0;
        while(i<n){
            if(pivot==2){
                i++;
                pivot=0;
            }
            else{
                count+=nums[i];
                i++;
                pivot++;
            }
        }
        return count;
    }
};