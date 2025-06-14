class Solution {
public:
    vector<int>dp;
    int find(vector<int>&v,int i){
        int n=v.size();
        if(i==n-1) return v[n-1];
        else if(i==n-2) return max(v[n-2],v[n-1]);
        if(dp[i]!=-1) return dp[i];
        return dp[i]=max(v[i]+find(v,i+2),find(v,i+1));
    }
    int rob(vector<int>& nums) {
        dp.assign(405, -1); //we cannot assign vector size and values outside function;
        int idx=0;
        int a=find(nums,idx);
        return a;
    }
};