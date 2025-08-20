class Solution {
public:
    vector<vector<int>>dp;
    bool find(vector<int>& nums,int i,int l){
        int n=nums.size();
        if(i==n-1) return true;
        if(i>=n) return false;
        if(dp[i][l]!=-1) return dp[i][l];
        if(i==0){
            if(nums[1]-nums[0] == 1){
                return find(nums,i+1,l+1);
            }
            else return false;
        }
        else{
            if(i!=1){
                for(int k=i+1;k<n;k++){
                    if(nums[k]==nums[i]+(l-1)){
                        bool a=find(nums,k,nums[k]-nums[i]);
                        if(a==true) return dp[i][l]=true;
                    }
                    
                }
            }
            for(int k=i+1;k<n;k++){
                if(nums[k]==nums[i]+(l+1)){
                    bool a=find(nums,k,nums[k]-nums[i]);
                    if(a==true) return dp[i][l]=true;
                }
                
            }
            for(int k=i+1;k<n;k++){
                if(nums[k]==nums[i]+l){
                    bool a=find(nums,k,nums[k]-nums[i]);
                    if(a==true) return dp[i][l]=true;
                }

            }
        }
        return dp[i][l]=false;
    }
    bool canCross(vector<int>& stones) {
        if(stones.size()==1) return true;
        dp.resize(stones.size()+1,vector<int>(stones.size()+1,-1));
        return find(stones,0,0);
    }
};