class Solution {
public:
    int n1;
    int n2;
    vector<vector<int>>dp;
    int find(string &s1,string &s2,int i,int j){
        if(i>=n1 && j>=n2) return 0;
        else if(i>=n1){
            return n2-j;
        }
        else if(j>=n2){
            return n1-i;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j]){
            return dp[i][j]=find(s1,s2,i+1,j+1);
        }
        else{
            int a=find(s1,s2,i,j+1);
            int b=find(s1,s2,i+1,j);
            int c=find(s1,s2,i+1,j+1);
            return dp[i][j]=1+min({a,b,c});
        }
        
    }
    int minDistance(string word1, string word2) {
        n1=word1.length();
        n2=word2.length();
        dp.resize(n1+1,vector<int>(n2+1,-1));
        return find(word1,word2,0,0);
    }
};