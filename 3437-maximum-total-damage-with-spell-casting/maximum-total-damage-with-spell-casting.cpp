class Solution{
public:
    // int j=lower_bound(begin(nums)+i+1,end(nums),nums[i]+3)-begin(nums);
    int n;
    unordered_map<long long,long long>map;
    vector<long long>dp;
    long long find(vector<int>& nums,int i){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        long long not_take=find(nums,i+1);

        int j=lower_bound(begin(nums)+i+1,end(nums),nums[i]+3)-begin(nums);// find first index that is just >= nums[i]+3;

        long long take=nums[i]*map[nums[i]]+find(nums,j);
        return dp[i]=max(not_take,take);
    }
    long long maximumTotalDamage(vector<int>& nums){
        n=nums.size();
        for(int i=0;i<nums.size();i++){
            map[nums[i]]++;
        }
        dp.resize(n+1,-1);
        sort(nums.begin(),nums.end());
        return find(nums,0);
    }
};