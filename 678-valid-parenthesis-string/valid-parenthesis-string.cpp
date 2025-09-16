class Solution {
public:
    vector<vector<int>>dp;
    bool find(string &s,int i,int cnt){
        if(cnt<0) return false;
        if(i==s.length()){
            if(cnt==0) return true;
            else return false;
        }
        if(dp[i][cnt]!=-1) return dp[i][cnt];
        if(s[i]=='(') return dp[i][cnt]=find(s,i+1,cnt+1);
        else if(s[i]==')') return dp[i][cnt]=find(s,i+1,cnt-1);
        else{
            bool a=find(s,i+1,cnt+1);
            bool b=find(s,i+1,cnt);
            bool c=find(s,i+1,cnt-1);

            if(a==true || b==true || c==true) return dp[i][cnt]=true;
            else return dp[i][cnt]=false;
        }
    }
    bool checkValidString(string s) {
        int n=s.length();
        dp.resize(n+1,vector<int>(n+1,-1));
        return find(s,0,0);
    }
};