class Solution {
public:
    unordered_map<string,int>map;
    vector<vector<int>>dp;
    bool find(string &str,vector<string>& wordDict,int i,int j){
        if(j>=str.length()) return false;
        if(dp[i][j]!=-1) return dp[i][j];
        string s1=str.substr(i,j-i+1);
        bool a=false;
        bool b=false;
        if(map.find(s1)!=map.end()){
            if(j==str.length()-1) return true;
            a=find(str,wordDict,j+1,j+1);
        }
        b=find(str,wordDict,i,j+1);
        if(a==true || b==true) return dp[i][j]=true;
        else return dp[i][j]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=wordDict.size();
        int m=s.length();
        dp.resize(m+1,vector<int>(m+1,-1));
        for(int i=0;i<wordDict.size();i++){
            map[wordDict[i]]++;
        }
        string str="";
        return find(s,wordDict,0,0);

    }
};