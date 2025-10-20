class Solution {
public:
    vector<int>dp;
    int find(vector<int>&nums,int i){
        int n=nums.size();
        if(i>=n-1) return 0;
        int x=nums[i];
        if(x==0) return INT_MAX;
        int ans=INT_MAX;
        if(dp[i]!=-1) return dp[i];
        for(int l=1;l<=x;l++){
            int a=find(nums,i+l);

            if(a!=INT_MAX){
                ans=min(ans,1+a);
            }
        }
        return dp[i]=ans;
    }
    int jump(vector<int>& nums) {
        int n=nums.size();
        dp.resize(n+1,-1);
        int a=find(nums,0);
        if(a==INT_MAX) return 0;
        else return a;
    }
};