class Solution {
public:
    int n;
    int m;
    vector<vector<int>>dp;
    int find(vector<int>&nums1,vector<int>&nums2,int i,int j){
        if(i>=n || j>=m) return INT_MIN;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=0;
        int take=find(nums1,nums2,i+1,j+1);
        ans+=nums1[i]*nums2[j];
        int notTake=max(find(nums1,nums2,i+1,j),find(nums1,nums2,i,j+1));
        if(take>0){// if take is greater than 0 then anly add oyher wise it willl becone worse otherwise ans is compared later
            take+=ans;
            return dp[i][j]=max(take,notTake);
        }
        return dp[i][j]=max({ans,take,notTake});
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        n=nums1.size();
        m=nums2.size();
        dp.resize(n+1,vector<int>(m+1,-1));
        return find(nums1,nums2,0,0);
    }
};