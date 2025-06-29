class Solution {
public:
    vector<vector<int>>dp;
    int find(string &s1,string &s2,int i,int j,int &n1,int &n2){
        if(i>=n1 && j>=n2) return 0;
        if(i>=n1){
            int sum=0;
            for(int k=j;k<n2;k++){
                sum=sum+(int)s2[k];
            }
            return sum;
        }
        else if(j>=n2){
            int sum=0;
            for(int k=i;k<n1;k++){
                sum=sum+(int)s1[k];
            }
            return sum;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j]){
            return dp[i][j]=find(s1,s2,i+1,j+1,n1,n2);
        }
        else return dp[i][j]=min((int)s1[i]+find(s1,s2,i+1,j,n1,n2),(int)s2[j]+find(s1,s2,i,j+1,n1,n2));
    }
    int minimumDeleteSum(string s1, string s2) {
        int n1=s1.length();
        int n2=s2.length();
        dp.resize(n1+1,vector<int>(n2+1,-1));
        return find(s1,s2,0,0,n1,n2);
    }
};