class Solution {
public:
    vector<vector<int>>dp;
    int find(int n,int k){
        if(n<=1) return n;

        if(k==1) return n;
        if(dp[n][k]!=-1) return dp[n][k];
        int low=1;
        int high=n;
        int ans=n;

        while(low<=high){
            int mid=low+(high-low)/2;

            int left=find(mid-1,k-1);
            int right=find(n-mid,k);

            ans=min(ans,1+max(left,right));

            if(left>right) high=mid-1;
            else low=mid+1;
        }
        return dp[n][k]=ans;
    }
    int superEggDrop(int k, int n){
        dp.resize(n+1,vector<int>(k+1,-1));
        return find(n,k);
    }
};