class Solution {
public:
    int n;
    vector<vector<int>>dp;
    int find(vector<vector<int>>&triangle,int i,int j){
        if(i>=n || j>=triangle[i].size()) return INT_MAX;
        if(dp[i][j]!=INT_MIN) return dp[i][j];
        int a=find(triangle,i+1,j);
        int b=find(triangle,i+1,j+1);
        
        if(a==INT_MAX && b==INT_MAX) return dp[i][j]=triangle[i][j];
        else return dp[i][j]=triangle[i][j]+min(find(triangle,i+1,j),find(triangle,i+1,j+1));
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        n=triangle.size();
        int m=triangle[n-1].size();
        dp.resize(n+1,vector<int>(m+1,INT_MIN));
        return find(triangle,0,0);
    }
};