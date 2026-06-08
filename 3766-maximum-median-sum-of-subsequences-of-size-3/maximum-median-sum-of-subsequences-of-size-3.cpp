class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int i=0;
        int j=n-2;
        long long sum=0;
        while(j>i){
            sum+=nums[j];
            j-=2;
            i++;
        }
        return sum; 
    }
};