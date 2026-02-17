class Solution {
public:
    int n;
    vector<vector<long long>>dp;
    long long find(vector<int>& nums, vector<int>& colors,int i,bool prev){
        if(i>=n) return 0;
        if(dp[i][prev]!=-1) return dp[i][prev];
        if(i==0){
            long long a=max(nums[i]+find(nums,colors,i+1,true),find(nums,colors,i+1,false));
            return dp[i][prev]=a;
        }
        else if(prev==true){
            if(colors[i-1]==colors[i]){
                long long a=find(nums,colors,i+1,false);
                return dp[i][prev]=a;
            }
            else{
                long long a=max(nums[i]+find(nums,colors,i+1,true),find(nums,colors,i+1,false));
                return dp[i][prev]=a;
            }
        }
        else{
            long long a=max(nums[i]+find(nums,colors,i+1,true),find(nums,colors,i+1,false));
            return dp[i][prev]=a;
        }
    }
    long long rob(vector<int>& nums, vector<int>& colors) {
        n=nums.size();
        dp.resize(n+1,vector<long long>(2,-1));
        return find(nums,colors,0,false);
    }
};