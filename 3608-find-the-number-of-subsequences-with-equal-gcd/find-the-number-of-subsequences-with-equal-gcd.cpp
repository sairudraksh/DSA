class Solution {
public:
    int n;
    long long mod=1e9+7;
    long long dp[202][202][202];
    long long find(vector<int>&nums,int i,int gcd1,int gcd2){
        if(i>=n){
            if(gcd1!=-1 && gcd1==gcd2){
                return 1;
            }
            return 0;
        }
        if(dp[i][gcd1+1][gcd2+1]!=-1) return dp[i][gcd1+1][gcd2+1];
        int newgcd1=0;
        int newgcd2=0;

        if(gcd1==-1) newgcd1=nums[i];
        else newgcd1=gcd(nums[i],gcd1);

        if(gcd2==-1) newgcd2=nums[i];
        else newgcd2=gcd(nums[i],gcd2);

        return dp[i][gcd1+1][gcd2+1]=(find(nums,i+1,newgcd1,gcd2) + find(nums,i+1,gcd1,newgcd2) + find(nums,i+1,gcd1,gcd2))%mod;
    }
    int subsequencePairCount(vector<int>& v) {
        n=v.size();
        
        memset(dp,-1,sizeof(dp));
        return find(v,0,-1,-1)%mod;
    }
};