class Solution {
public:
    vector<vector<double>>dp;
    vector<pair<double,double>>v={{100,0},{75,25},{50,50},{25,75}};
    double find(double A,double B){
        if(A<=0 && B<=0) return 0.5;
        if(A<=0) return 1.0;

        if(B<=0) return 0;
        if(dp[A][B]!=-1.0) return dp[A][B];
        double ans=0.0;
        for(auto &p:v){
            double x=p.first;
            double y=p.second;

            ans+=find(A-x,B-y);
        }
        return dp[A][B]=0.25*ans;
    }
    double soupServings(int n) {
        if(n>=5000) return 1;
        dp.resize(n+1,vector<double>(n+1,-1.0));
        return find(n,n);
    }
};