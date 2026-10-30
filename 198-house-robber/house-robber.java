class Solution {
    int[] dp=new int[101];
    public int find(int[] nums,int i){
        if(i>=nums.length) return 0;
        if(dp[i]!=-1) return dp[i];
        return dp[i]=Math.max(nums[i]+find(nums,i+2),find(nums,i+1));
    }
    public int rob(int[] nums) {
        Arrays.fill(dp,-1);
        return find(nums,0);
    }
}