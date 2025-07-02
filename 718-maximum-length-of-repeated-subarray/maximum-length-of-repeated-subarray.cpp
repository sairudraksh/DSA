class Solution {
public:
    int maxans=0;
    vector<vector<int>>dp;
    int find(vector<int>&nums1,vector<int>&nums2,int &n1,int &n2,int i,int j){
        if(i>=n1 || j>=n2) return 0;
        int ans=0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(nums1[i]==nums2[j]){
            ans=1+find(nums1,nums2,n1,n2,i+1,j+1);
            maxans=max(ans,maxans);
        }
        find(nums1,nums2,n1,n2,i,j+1);
        find(nums1,nums2,n1,n2,i+1,j);
        return dp[i][j]=ans;
    }
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        dp.resize(n1+1,vector<int>(n2+1,-1));
        int a=find(nums1,nums2,n1,n2,0,0);
        return maxans;

    }
};