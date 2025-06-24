class Solution {
public:
    vector<vector<int>>dp;
    bool find(int i,int j,int k,string &s1,string &s2,string &s3,int &n1,int &n2,int &n){
        if(k==n && i==n1 && j==n2) return true;
        else if(i==n1 && j==n2 && k!=n) return false;
        else if(i==n1 && j==n2) return false;
        else if(i==n1){
            while(j<=n2-1 && k<=n-1){
                if(s2[j]!=s3[k]) return false;
                k++;
                j++;
            }
            if(j==n2 && k==n) return true;
            else return false;
        }
        else if(j==n2){
            while(i<=n1-1 && k<=n-1){
                if(s1[i]!=s3[k]) return false;
                k++;
                i++;
            }
            if(i==n1 && k==n) return true;
            else return false;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        else if(s1[i]==s3[k] && s2[j]==s3[k]){
            return dp[i][j]=find(i+1,j,k+1,s1,s2,s3,n1,n2,n)|find(i,j+1,k+1,s1,s2,s3,n1,n2,n);
        }
        else if(s1[i]==s3[k]){
            return dp[i][j]=find(i+1,j,k+1,s1,s2,s3,n1,n2,n);
        }
        else if(s2[j]==s3[k]){
            return dp[i][j]=find(i,j+1,k+1,s1,s2,s3,n1,n2,n);
        }
        return dp[i][j]=false;//if none is matching;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n1=s1.length();
        int n2=s2.length();
        int n3=s3.length();
        dp.resize(201,vector<int>(201,-1));
        return find(0,0,0,s1,s2,s3,n1,n2,n3);
    }
};