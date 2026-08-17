class Solution {
public:
    int n;
    int dp[501][501];
    int find(int st,int end,vector<int>&prefix){
        if(st>=end) return 0;
        int maximum=INT_MIN;
        if(dp[st][end]!=-1)  return dp[st][end];
        for(int i=st+1;i<=end;i++){
            int sum1=0;
            if(st==0){
                sum1=prefix[i-1];
            }
            else sum1=prefix[i-1]-prefix[st-1];

            int sum2=prefix[end]-prefix[i-1];

            if(sum1>sum2){
                maximum=max(maximum,sum2+find(i,end,prefix));
            }
            else if(sum2>sum1){
                maximum=max(maximum,sum1+find(st,i-1,prefix));
            }
            else maximum=max(maximum,sum1+max(find(st,i-1,prefix),find(i,end,prefix)));
        }
        return dp[st][end]=maximum;
    }
    int stoneGameV(vector<int>& stone) {
        n=stone.size();
        vector<int>prefix(n,stone[0]);

        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+stone[i];
        }
        memset(dp,-1,sizeof(dp));
        return find(0,n-1,prefix);
    }
};