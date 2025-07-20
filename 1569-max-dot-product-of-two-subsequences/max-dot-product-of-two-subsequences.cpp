class Solution {
public:
    vector<vector<int>>dp;
    int find(vector<int>& nums1, vector<int>& nums2,int i,int j){
        if(i>=nums1.size() || j>=nums2.size()) return INT_MIN;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=nums1[i]*nums2[j]+max(0,find(nums1,nums2,i+1,j+1));// any value returninng less than 0 includein int min means it is decreasing the solution so there is no point to take it

        //not taking
        int ans1=find(nums1,nums2,i+1,j);
        int ans2=find(nums1,nums2,i,j+1);
        return dp[i][j]=max({ans,ans1,ans2});
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        dp.resize(n1+1,vector<int>(n2+1,-1));
        return find(nums1,nums2,0,0);
    }
};