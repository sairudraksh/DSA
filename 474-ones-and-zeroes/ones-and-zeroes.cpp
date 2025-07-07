class Solution {
public:
    vector<vector<int>>count;
    int maxcount=0;
    vector<vector<vector<int>>>dp;
    void ans(int i,int n,int m,int &ansm,int &ansn,int &countt){
        if(i>=count.size()) return;
        if (n>ansn || m>ansm) return;
        if (dp[i][n][m] != -1 && dp[i][n][m] >= countt) return;
        dp[i][n][m] = countt;
        m+=count[i][0];
        n+=count[i][1];
        countt++;
        if(m<=ansm && n<=ansn){
            maxcount=max(maxcount,countt);
        }
        if (m<=ansm && n<=ansn){
            ans(i+1,n,m,ansm,ansn,countt);
        }
        m-=count[i][0];
        n-=count[i][1];
        countt--;
        ans(i+1,n,m,ansm,ansn,countt);
    }
    void find(string strs, int &a, int &b){
        for(int i=0;i<strs.size();i++){
            if(strs[i]=='0') a++;
            else b++;
        }
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        for(int i=0;i<strs.size();i++){
            int a=0;
            int b=0;
            find(strs[i],a,b);
            count.push_back({a,b});
        }
        int p=0;
        dp.resize(strs.size(), vector<vector<int>>(n + 1, vector<int>(m + 1, -1)));
        ans(0,0,0,m,n,p);
        return maxcount;
    }
};