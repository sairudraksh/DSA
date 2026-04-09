class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        vector<int>v=nums;
        vector<int>v1=nums;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        
        int sum=0;
        sum+=nums[n-1]-nums[2];
        nums[n-1]=nums[0];
        nums[n-2]=nums[0];
        sort(nums.begin(),nums.end());
        sum=min(sum,nums[n-1]-nums[0]);
        sort(v.begin(),v.end());
        v[0]=v[1];
        v[n-1]=v[1];
        sort(v.begin(),v.end());
        sum=min(sum,v[n-1]-v[0]);

        sort(v1.begin(),v1.end());
        v1[0]=v1[v.size()-2];
        v1[n-1]=v1[v.size()-2];
        sort(v1.begin(),v1.end());
        sum=min(sum,v1[n-1]-v1[0]);

        return sum;
    }
};