class Solution {
public:
    int M=1e9+7;
    string states[12]={"RYG","RGY","RYR","RGR","YRG","YGR","YGY","YRY","GRY","GYR","GRG","GYG"};// all possible states for first row;
    vector<vector<int>>dp;
    int find(int n,int i){
        if(n==0) return 1;
        int ans=0;
        if(dp[n][i]!=-1) return dp[n][i];
        string prev=states[i];
        for(int j=0;j<12;j++){
            string curr=states[j];
            if(curr==prev) continue;
            bool conflict=false;
            for(int l=0;l<3;l++){
                if(curr[l]==prev[l]){
                    conflict=true;
                    break;
                }
            }
            if(!conflict) ans=(ans+find(n-1,j))%M;
        }
        return dp[n][i]=ans;
    }
    int numOfWays(int n) {
        int result=0;
        dp.resize(n+1,vector<int>(12,-1));
        for(int i=0;i<12;i++){
            result=(result+find(n-1,i))%M;
        }
        return result;
    }
};