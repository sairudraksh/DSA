class Solution {
public:
    vector<vector<int>>dp;
    int find(vector<string>& strs,int prev,int i){
        if(i>=strs[0].length()) return 0;
        int ans=INT_MAX;
        if(dp[prev+1][i]!=-1) return dp[prev+1][i];
        if(prev!=-1){
            bool found=false;
            for(int j=0;j<strs.size();j++){
                if(strs[j][i]<strs[j][prev]){
                    found=true;
                    break;
                }
            }
            if(found==false){
                ans=min({ans,1+find(strs,prev,i+1),find(strs,i,i+1)});
            }
            else{
                ans=min(ans,1+find(strs,prev,i+1));
            }
        }
        if(prev==-1){
            ans=min({ans,1+find(strs,prev,i+1),find(strs,i,i+1)});
        }
        return dp[prev+1][i]=ans;
    }
    int minDeletionSize(vector<string>& strs) {
        int n=strs[0].length();
        dp.resize(n+2,vector<int>(n+1,-1));
        return find(strs,-1,0);
    }
};