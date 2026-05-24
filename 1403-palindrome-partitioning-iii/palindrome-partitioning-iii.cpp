class Solution {
public:
    int dp[101][101][101];
    int findlen(string &s,int i,int j){
        int count=0;
        while(i<j){
            if(s[i]!=s[j]) count++;
            i++;
            j--;
        }
        return count;
    }
    int find(string &s,int i,int j,int k){
        if(i>=s.length()){
            if(k==0) return 0;
            return INT_MAX;
        }
        if(j>=s.length()){
            if(k==1){
                return findlen(s,i,j-1);
            }
            return INT_MAX;
        }
        if(dp[i][j][k]!=-1) return dp[i][j][k];
        if(k==0) return INT_MAX;
        int curr=findlen(s,i,j);
        int a=find(s,j+1,j+1,k-1);
        if(a!=INT_MAX) a+=curr;
        int b=find(s,i,j+1,k);

        return dp[i][j][k]=min(a,b);
    }
    int palindromePartition(string s, int k) {
        memset(dp,-1,sizeof(dp));
        return find(s,0,0,k);
    }
};