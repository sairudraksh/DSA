class Solution {
public:
    int dp[101][101][101];
    int mod=1e9+7;
    int find(int n,int &minProfit,vector<int>& group, vector<int>& profit,int sum,int i){
        if(i>=group.size() && sum>=minProfit) return 1;
        if(i>=group.size()) return 0;
        int key = min(sum, minProfit);
        if(dp[key][i][n]!=-1) return dp[key][i][n];
        if(sum>=minProfit){
            int take=0;
            int notTake=0;

            int membersLeft=n-group[i];

            if(membersLeft<0){
                return dp[key][i][n]=find(n,minProfit,group,profit,sum,i+1)%mod;
            }
            else{
                return dp[key][i][n]=(find(n,minProfit,group,profit,sum,i+1)%mod+find(membersLeft,minProfit,group,profit,sum+profit[i],i+1)%mod)%mod;
            }
        }
        else{
            int membersLeft=n-group[i];

            if(membersLeft<0){
                return dp[key][i][n]=find(n,minProfit,group,profit,sum,i+1)%mod;
            }
            else{
                return dp[key][i][n]=(find(n,minProfit,group,profit,sum,i+1)%mod+find(membersLeft,minProfit,group,profit,sum+profit[i],i+1)%mod)%mod;
            }
        }
    }
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        memset(dp,-1,sizeof(dp));
        return find(n,minProfit,group,profit,0,0)%mod;
    }
};