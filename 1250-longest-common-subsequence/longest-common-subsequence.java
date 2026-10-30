class Solution {
    int[][] dp=new int[1001][1001];
    int n;
    int m;
    public int find(String text1,String text2,int i,int j){
        if(i>=n || j>=m) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(text1.charAt(i)==text2.charAt(j)){
            return dp[i][j]=1+find(text1,text2,i+1,j+1);
        }
        else return dp[i][j]= Math.max(find(text1,text2,i+1,j),find(text1,text2,i,j+1));
    }
    public int longestCommonSubsequence(String text1, String text2) {
        n=text1.length();
        m=text2.length();
        for(int i=0;i<n;i++){
            Arrays.fill(dp[i],-1);
        }
        return find(text1,text2,0,0);
    }
}