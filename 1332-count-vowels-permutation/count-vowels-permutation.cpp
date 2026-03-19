class Solution {
public:
    vector<vector<int>>dp;
    long long mod=1e9+7;
    long long find(int &n,int count,int idx){
        if(count==n) return 1;

        if(dp[count][idx+1]!=-1) return dp[count][idx+1];

        long long sum=0;
        if(idx==-1){
            for(int i=0;i<5;i++){
                sum+=find(n,count+1,i)%mod;
            }
        }

        else{
            if(idx==0){
                sum+=find(n,count+1,1)%mod;
            }
            else if(idx==1){
                sum+=find(n,count+1,0)%mod;
                sum+=find(n,count+1,2)%mod;
            }
            else if(idx==2){
                sum+=find(n,count+1,0)%mod;
                sum+=find(n,count+1,1)%mod;
                sum+=find(n,count+1,3)%mod;
                sum+=find(n,count+1,4)%mod;
            }
            else if(idx==3){
                sum+=find(n,count+1,4)%mod;
                sum+=find(n,count+1,2)%mod;
            }
            else if(idx==4){
                sum+=find(n,count+1,0)%mod;
            }
        }
        return dp[count][idx+1]=(sum)%mod;
    }
    int countVowelPermutation(int n) {
        dp.resize(n+1,vector<int>(6,-1));
        return find(n,0,-1)%mod;
    }
};