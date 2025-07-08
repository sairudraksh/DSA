class Solution {
public:
    vector<vector<int>>ans;
    vector<vector<vector<int>>>dp;
    int maxcount=0;
    void find(int i,int ansm,int ansn,int &m,int &n,int &count){
        if(i>=ans.size()) return;
        if (dp[i][ansn][ansm]!= -1 && dp[i][ansn][ansm]>=count) return;
        dp[i][ansn][ansm] = count;
        if(ansm>m || ansn>n){
            return;
        }
        ansm+=ans[i][0];
        ansn+=ans[i][1];
        count+=1;
        if(ansm<=m && ansn<=n){
            maxcount=max(count,maxcount);
            find(i+1,ansm,ansn,m,n,count);
        }
        count-=1;
        ansm-=ans[i][0];
        ansn-=ans[i][1];
        find(i+1,ansm,ansn,m,n,count);
    }
    void summ(string str){
        int a=0;// 0 count;
        int b=0;// 1 count;
        for(int i=0;i<str.length();i++){
            if(str[i]=='0') a++;
            else b++;
        }
        ans.push_back({a,b});
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        dp.resize(strs.size(), vector<vector<int>>(n + 1,vector<int>(m + 1, -1)));
        for(int i=0;i<strs.size();i++){
            summ(strs[i]);
        }
        int count=0;
        find(0,0,0,m,n,count);
        return maxcount;
    }
};