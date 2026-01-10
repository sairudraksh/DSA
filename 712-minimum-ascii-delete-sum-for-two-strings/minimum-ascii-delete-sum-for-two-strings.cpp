class Solution {
public:
    int n;
    int m;
    vector<vector<int>>dp;
    int find(string &s1,string &s2,int i,int j){
        if(i>=n && j>=m) return 0;
        if(i>=n){
            int sum=0;
            while(j<m){
                char ch=s2[j];
                int a=int(ch);
                sum+=a;
                j++;
            }
            return sum;
        }
        if(j>=m){
            int sum=0;
            while(i<n){
                char ch=s1[i];
                int a=int(ch);
                sum+=a;
                i++;
            }
            return sum;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j]){
            return dp[i][j]=find(s1,s2,i+1,j+1);
        }
        else{
            return dp[i][j]=min(int(s1[i])+find(s1,s2,i+1,j),int(s2[j])+find(s1,s2,i,j+1));
        }
    }
    int minimumDeleteSum(string s1, string s2) {
        n=s1.length();
        m=s2.length();
        dp.resize(n+1,vector<int>(m+1,-1));
        return find(s1,s2,0,0);
    }
};