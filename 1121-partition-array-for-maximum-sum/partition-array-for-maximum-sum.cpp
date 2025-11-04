class Solution {
public:
    int n;
    vector<int>dp;
    int find(vector<int>&nums,int i,int &k){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        int maximum=0;
        int ans=0;
        for(int j=i;j<n && j<=i+k-1;j++){
            maximum=max(maximum,nums[j]);
            ans=max(ans,(maximum*(j-i+1))+find(nums,j+1,k));
        }
        return dp[i]=ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        n=arr.size();
        dp.resize(n+1,-1);
        return find(arr,0,k);
    }
};