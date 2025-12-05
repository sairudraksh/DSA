class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n=nums.size();
        int total=0;
        int count=0;
        for(int i=0;i<n;i++){
            total+=nums[i];
        }
        int sum=nums[0];
        for(int i=1;i<=n-1;i++){
            int x=total-sum;
            if(abs(x-sum)%2==0) count++;
            sum+=nums[i];
        }
        return count;
    }
};