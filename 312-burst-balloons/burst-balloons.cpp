class Solution {
public:
    vector<vector<int>>dp;
    int find(vector<int>& nums,int i,int j){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        int maximum=INT_MIN;
        for(int k=i;k<=j;k++){
            maximum=max(maximum,(nums[i-1]*nums[k]*nums[j+1])+find(nums,i,k-1)+find(nums,k+1,j));
        }

        return dp[i][j]=maximum;
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        int n=nums.size();
        dp.resize(n+1,vector<int>(n+1,-1));
        return find(nums,1,n-2);
    }
};