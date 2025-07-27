class Solution {
public:
    vector<int>dp;
    int find(vector<int>& days, vector<int>& cost,int idx){
        if(idx>=days.size()) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int option1=cost[0]+find(days,cost,idx+1);

        int i=idx;
        for(i=idx+1;i<days.size() && days[i]<days[idx]+7;i++);
        int option2=cost[1]+find(days,cost,i);

        for(i=idx+1;i<days.size() && days[i]<days[idx]+30;i++);
        int option3=cost[2]+find(days,cost,i);

        return dp[idx]=min({option1,option2,option3});

    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        dp.resize(n+1,-1);
        return find(days,costs,0);
    }
};