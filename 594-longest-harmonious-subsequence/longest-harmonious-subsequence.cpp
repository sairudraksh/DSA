class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int j=0;
        int maxlength=0;
        for(int i=0;i<n;i++){
            if(nums[i]-nums[j]>1){
                j++;
            }
            if(nums[i]-nums[j]==1){
                maxlength=max(maxlength,i-j+1);
            }
        }
        return maxlength;
    }
};