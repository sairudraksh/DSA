class Solution {
public:
    int dp[101][101][21];
    int find(vector<int>&nums,vector<vector<int>>& cost,int &target,int i,int curr,int dist){
        if(dist>target) return INT_MAX/2;
        if(i>=nums.size() && dist==target) return 0;
        if(i>=nums.size()) return INT_MAX/2;
        if(dp[dist][i][curr]!=-1) return dp[dist][i][curr];
        if(nums[i]!=0){
            if(i==0){
                return dp[dist][i][curr]=find(nums,cost,target,i+1,nums[i],dist+1);
            }
            else if(nums[i]!=curr){
                return dp[dist][i][curr]=find(nums,cost,target,i+1,nums[i],dist+1);
            }
            else{
                return dp[dist][i][curr]=find(nums,cost,target,i+1,nums[i],dist);
            }
        }
        int ans=INT_MAX/2;
        auto v=cost[i];
        if(i==0){
        
            for(int j=0;j<v.size();j++){
                ans=min(ans,v[j]+find(nums,cost,target,i+1,j+1,dist+1));
            }
        }
        else{
            for(int j=0;j<v.size();j++){
                if(dist==target){
                    if(j+1==curr){
                        ans=min(ans,v[j]+find(nums,cost,target,i+1,curr,dist));
                    }
                }
                else{
                    if(j+1==curr){
                        ans=min(ans,v[j]+find(nums,cost,target,i+1,curr,dist));
                    }
                    else ans=min(ans,v[j]+find(nums,cost,target,i+1,j+1,dist+1));
                }
            }
        }
        return dp[dist][i][curr]=ans;
    }
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        memset(dp,-1,sizeof(dp));
        int a=find(houses,cost,target,0,0,0);
        if(a!=INT_MAX/2) return a;
        int count=1;
        for(int i=1;i<houses.size();i++){
            if(houses[i]==0) return -1;
            else if(houses[i]!=houses[i-1]) count++;
        }
        if(count==target) return 0;
        return -1;
    }
};