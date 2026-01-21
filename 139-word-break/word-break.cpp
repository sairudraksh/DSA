class Solution {//string s1=s.substr(i,j-i+1);
public:
    unordered_map<string,int>map;
    vector<vector<int>>dp;
    int find(int i,int j,string &s){
        if(i>=s.length() && j>=s.length()) return true;
        if(i>=s.length() || j>=s.length()) return false;
        if(dp[i][j]!=-1) return dp[i][j];
        string s1=s.substr(i,j-i+1);

        if(map.find(s1)!=map.end()){
            return dp[i][j]=(find(j+1,j+1,s) || find(i,j+1,s));
        }
        else{
            return dp[i][j]=find(i,j+1,s);
        }
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=wordDict.size();
        for(int i=0;i<wordDict.size();i++){
            map[wordDict[i]]++;
        }
        dp.resize(s.length()+1,vector<int>(s.length()+1,-1));
        return find(0,0,s);
    }
};