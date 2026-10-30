class Solution {
    int[] dp=new int[46];
    int find(int curr,int n){
        if(curr==n) return 1;
        if(curr>n) return 0;
        if(dp[curr]!=-1) return dp[curr];
        return dp[curr]=(find(curr+1,n) + find(curr+2,n));
    }
    public int climbStairs(int n) {
        Arrays.fill(dp,-1);
        return find(0,n);
    }
}