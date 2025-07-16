class Solution {
public:
    vector<vector<int>>dp;
    int find(string &word1,string &word2,int i,int j){
        if(i==-1 && j==-1) return 0;
        else if(i==-1 && j!=-1){
            return j+1;
        }
        else if(i!=-1 && j==-1){
            return i+1;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(word1[i]==word2[j]){
            return dp[i][j]=find(word1,word2,i-1,j-1);
        }
        return dp[i][j]=1+min({find(word1,word2,i-1,j-1),find(word1,word2,i-1,j),find(word1,word2,i,j-1)});
        
    }
    int minDistance(string word1, string word2) {
        dp.resize(word1.size()+1,vector<int>(word2.size()+1,-1));
        return find(word1,word2,word1.length()-1,word2.length()-1);
    }
};