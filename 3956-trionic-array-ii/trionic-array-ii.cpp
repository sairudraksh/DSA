class Solution {
public:
    int n;
    vector<vector<long long>>dp;
    long long find(vector<int>&nums,int i,int trend){
        if(i>=n){
            if(trend==3) return 0;
            return LLONG_MIN/2;
        }
        if(dp[i][trend]!=LLONG_MIN) return dp[i][trend];
        long long take=LLONG_MIN/2;
        long long skip=LLONG_MIN/2;


        // skip;
        if(trend==0){
            skip=find(nums,i+1,0);
        }
        if(trend==3){
            take=nums[i];
        }

        // take
        if(i+1<n){
            if(trend==0){
                if(nums[i+1]>nums[i]){
                    take=max(take,nums[i]+find(nums,i+1,1));
                }
            }
            else if(trend==1){
                if(nums[i+1]<nums[i]){
                    take=max(take,nums[i]+find(nums,i+1,2));
                }
                else if(nums[i+1]>nums[i]){
                    take=max(take,nums[i]+find(nums,i+1,1));
                }
            }
            else if(trend==2){
                if(nums[i+1]<nums[i]){
                    take=max(take,nums[i]+find(nums,i+1,2));
                }
                else if(nums[i+1]>nums[i]){
                    take=max(take,nums[i]+find(nums,i+1,3));
                }
            }
            else if(trend==3){
                if(nums[i+1]>nums[i]){
                    take=max(take,nums[i]+find(nums,i+1,3));
                }
            }
        }
        return dp[i][trend]=max(take,skip);
    }
    long long maxSumTrionic(vector<int>& nums) {
        n=nums.size();
        dp.resize(n+1,vector<long long>(4,LLONG_MIN));
        return find(nums,0,0);
    }
};