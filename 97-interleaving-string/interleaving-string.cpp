class Solution {
public:
    vector<vector<int>>dp;
    bool find(string &s1,string &s2,string &s3,int i,int j,int k,int &n1,int &n2,int &n3){
        if(i==n1 && j==n2 && k==n3) return true;
        else if(i==n1 && j==n2 && k!=n3) return false;
        if(i==n1 && j==n2) return false;
        if(dp[i][j]!=-1) return dp[i][j];
        else if(i==n1 && j!=n2){
            while(k<n3 && j<n2){
                if(s2[j]!=s3[k]) return false;
                j++;
                k++;
            }
            if(j==n2 && k==n3) return dp[i][j]=true;
            else return false;
        }

        else if(i!=n1 && j==n2){
            while(k<n3 && i<n1){
                if(s1[i]!=s3[k]) return false;
                i++;
                k++;
            }
            if(i==n1 && k==n3) return dp[i][j]=true;
            else return false;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s3[k] && s2[j]==s3[k]){
            return dp[i][j]=find(s1,s2,s3,i+1,j,k+1,n1,n2,n3)|find(s1,s2,s3,i,j+1,k+1,n1,n2,n3);
        }
        else if(s1[i]==s3[k]){
            return dp[i][j]=find(s1,s2,s3,i+1,j,k+1,n1,n2,n3);
        }
        else if(s2[j]==s3[k]){
            return dp[i][j]=find(s1,s2,s3,i,j+1,k+1,n1,n2,n3);
        }
        return dp[i][j]=false;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n1=s1.length();
        int n2=s2.length();
        int n3=s3.length();
        int k=0;
        dp.resize(201,vector<int>(201,-1));
        return find(s1,s2,s3,0,0,k,n1,n2,n3);
    }
};