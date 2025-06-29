class Solution {
public:
    int find(vector<int>& nums1,vector<int>& nums2,int i,int j,int &n1,int &n2,vector<vector<int>>&dp){
        if(i>=n1 || j>=n2) return 0;
        if(nums1[i]==nums2[j]){
            return 1+find(nums1,nums2,i+1,j+1,n1,n2,dp);
        }
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j]=max(find(nums1,nums2,i+1,j,n1,n2,dp),find(nums1,nums2,i,j+1,n1,n2,dp));
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,-1));
        return find(nums1,nums2,0,0,n1,n2,dp);
    }
};