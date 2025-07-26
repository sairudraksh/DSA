class Solution {
public:
    vector<vector<int>>dp;
    bool find(string &s,string &p,int i,int j){
        if(i==-1 && j==-1) return true;
        else if(j<0 && i>=0) return false;
        else if(i<0 && j>=0){
            for(int k=0;k<=j;k++){
                if(p[k]!='*') return false;
            }
            return true; 
        } 
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==p[j] || p[j]=='?'){// cannot skip here as it should be continous
            return dp[i][j]=find(s,p,i-1,j-1);
        }
        else if(p[j]=='*'){
            return dp[i][j]=find(s,p,i-1,j) | find(s,p,i,j-1);// slip * as it can match empty also
        }
        return dp[i][j]=false;
    }
    bool isMatch(string s, string p) {
        int n=s.length();
        int m=p.length();
        dp.resize(n+1,vector<int>(m+1,-1));
        return find(s,p,n-1,m-1);
    }
};