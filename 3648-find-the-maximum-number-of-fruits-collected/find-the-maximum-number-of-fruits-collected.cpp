class Solution {
public:
    vector<vector<int>>dp;

    int first(vector<vector<int>>& nums){
        int sum=0;

        for(int i=0;i<nums.size();i++){
            sum+=nums[i][i];
            nums[i][i]=0;
            dp[i][i]=0;
        }

        return sum;
    }

    int second(vector<vector<int>>& nums,int i, int j){
        int n=nums.size();

        if(i>=n || j>=n || i<0 || j<0 || i>j) return 0;
        if(i==n-1 && j==n-1) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        int a=nums[i][j]+second(nums,i+1,j-1);
        int b=nums[i][j]+second(nums,i+1,j);
        int c=nums[i][j]+second(nums,i+1,j+1);

        return dp[i][j]=max({a,b,c});
    }

    int third(vector<vector<int>>& nums,int i, int j){
        int n=nums.size();

        if(i>=n || j>=n || i<0 || j<0 || i<j) return 0;
        if(i==n-1 && j==n-1) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        int a=nums[i][j]+third(nums,i-1,j+1);
        int b=nums[i][j]+third(nums,i,j+1);
        int c=nums[i][j]+third(nums,i+1,j+1);

        return dp[i][j]=max({a,b,c});
    }

    int maxCollectedFruits(vector<vector<int>>& nums) {
        int n=nums.size();

        dp.resize(n+1,vector<int>(n+1,-1));

        int a=first(nums);
        int b=second(nums,0,n-1);
        int c=third(nums,n-1,0);

        return a+b+c;
    }
};