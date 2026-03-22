class Solution {
public:
    vector<int>dp;
    int mod=1e9+7;
    int find(int &low,int &high,int &zero,int &one,int count){
        if(count>high) return 0;
        if(dp[count]!=-1) return dp[count];

        if(count>=low && count<=high) {
            int a=(find(low,high,zero,one,count+zero)%mod + find(low,high,zero,one,count+one)%mod)%mod;
            return dp[count]=a+1;
        }

        return dp[count]=(find(low,high,zero,one,count+zero)%mod + find(low,high,zero,one,count+one)%mod)%mod;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        dp.resize(high+1,-1);
        return find(low,high,zero,one,0);
    }
};