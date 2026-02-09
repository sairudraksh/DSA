class Solution {
public:
    int n;
    int m;
    long long dp[101][101][101];
    long long find(vector<int>& nums1, vector<int>& nums2,int i,int j,int k){
        if(k==0) return 0;
        if(i>=n ||  j>=m) return LLONG_MIN/4;
        if(dp[i][j][k]!=LLONG_MIN) return dp[i][j][k];
        long long take=1LL*nums1[i]*nums2[j]+find(nums1,nums2,i+1,j+1,k-1);

        long long notTake=max(find(nums1,nums2,i+1,j,k),find(nums1,nums2,i,j+1,k));

        return dp[i][j][k]=max(take,notTake);
    }
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        n=nums1.size();
        m=nums2.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                for(int t=0;t<=k;t++){
                    dp[i][j][t]=LLONG_MIN;
                }
            }
        }
        long long a=find(nums1,nums2,0,0,k);
        return a;
    }
};