class Solution {
public:
    int n;
    vector<vector<int>>dp;
    bool isTrue(vector<string>&words,int k,int previdx){
        if(words[k].length()!=words[previdx].length()+1) return false;
        int i=0;
        int j=0;
        int count=0;
        string s1=words[k];
        string s2=words[previdx];
        while(i<words[k].length() && j<words[previdx].length()){
            if(s1[i]!=s2[j]){
                count++;
                i++;
            }
            else{
                i++;
                j++;
            }
            if(count>1) return false;
        }
        if(count>1) return false;
        return true;
    }
    int find(vector<string>&words,int i,int previdx){
        if(i>=n) return 0;
        if(dp[i][previdx+1]!=-1) return dp[i][previdx+1];
        if(previdx==-1){
            return dp[i][previdx+1]=max(1+find(words,i+1,i),find(words,i+1,previdx));
        }
        else{
            int a=0;
            int b=0;
            a=find(words,i+1,previdx);
            if(isTrue(words,i,previdx)){
                b=1+find(words,i+1,i);
            }
            return dp[i][previdx+1]=max(a,b);
        }
    }
    int longestStrChain(vector<string>& words) {
        n=words.size();
        sort(words.begin(), words.end(), [](const string &a,const string &b){
            return a.size() < b.size();
        });
        dp.resize(n+1,vector<int>(n+1,-1));
        return find(words,0,-1);
    }
};