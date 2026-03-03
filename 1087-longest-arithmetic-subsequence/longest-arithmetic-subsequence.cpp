class Solution {
public:
    int n;
    int dp[1001][1003];
    int find(vector<int>&nums,int i,int diff){
        if(i>=n) return 0;
        int maximum=0;
        int a=0;
        if(dp[i][diff+501]!=-1) return dp[i][diff+501];
        if(diff==-501) a=find(nums,i+1,-501);
        for(int j=i+1;j<n;j++){
            if(diff==-501 || nums[j]-nums[i]==diff){
                maximum=max(maximum,1+find(nums,j,nums[j]-nums[i]));
            }
        }
        return dp[i][diff+501]=max(a,maximum);
    }
    int longestArithSeqLength(vector<int>& nums) {
        n=nums.size();
        memset(dp,-1,sizeof(dp));
        return find(nums,0,-501)+1;
    }
};