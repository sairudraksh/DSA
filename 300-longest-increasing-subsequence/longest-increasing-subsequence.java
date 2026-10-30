class Solution {
    int[][] dp=new int[2502][2502];
    public int find(int[] nums,int prev,int i){
        if(i>=nums.length) return 0;
        if(dp[prev+1][i]!=-1) return dp[prev+1][i];
        if(prev==-1 || nums[prev]<nums[i]){
            return dp[prev+1][i]=Math.max(1+find(nums,i,i+1),find(nums,prev,i+1));
        }
        else return dp[prev+1][i]=find(nums,prev,i+1);

    }
    public int lengthOfLIS(int[] nums) {
        int n=nums.length;
        for(int i=0;i<n;i++){
            Arrays.fill(dp[i],-1);
        }
        return find(nums,-1,0);
    }
}