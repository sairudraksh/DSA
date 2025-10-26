class Solution {
public:
    unordered_map<string,int>map;
    vector<vector<int>>dp;
    bool find(string s,int i,int j){
        if(j>=s.length()) return false;
        if(dp[i][j]!=-1) return dp[i][j];
        string s1=s.substr(i,j-i+1);
        bool a=false;
        bool b=false;

        if(map.find(s1)!=map.end()){
            if(j==s.length()-1) return dp[i][j]=true;
            a=find(s,j+1,j+1);
        }
        b=find(s,i,j+1);

        if(a==true || b==true) return dp[i][j]=true;
        return dp[i][j]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.length();
        dp.resize(n+1,vector<int>(n+1,-1));
        for(int i=0;i<wordDict.size();i++){
            map[wordDict[i]]++;
        }
        return find(s,0,0);
    }
};