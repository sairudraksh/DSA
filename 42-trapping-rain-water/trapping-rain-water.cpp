class Solution {
public:
    int trap(vector<int>& nums){
        int n=nums.size();
        vector<int>prev(n,nums[0]);
        vector<int>next(n,nums[n-1]);

        for(int i=1;i<n;i++){
            prev[i]=max(prev[i-1],nums[i]);
        }
        for(int i=n-2;i>=0;i--){
            next[i]=max(next[i+1],nums[i]);
        }
        int sum=0;
        for(int i=1;i<n-1;i++){
            sum+=min(prev[i],next[i])-nums[i];
        }

        return sum;

    }
};